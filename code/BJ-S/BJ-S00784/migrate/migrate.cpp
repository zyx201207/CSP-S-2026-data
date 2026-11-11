#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=4e3+5,mod=1e9+7,INF=1e9+10;
int x[N],dis[N],cnt[N];
int ju(int hhz,int hh){
    return abs(hhz-hh);
}
int n,d;
int get(int l){
    memset(dis,0x3f,sizeof(dis));
    memset(cnt,0,sizeof(cnt));
    dis[l]=0;
    cnt[l]=1;
    int ans=0;
    for(int i=l;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(ju(x[i],x[j])<=d){
                if(dis[j]>dis[i]+1){
                    dis[j]=dis[i]+1;
                    cnt[j]=cnt[i];
                }else if(dis[j]==dis[i]+1){
                    cnt[j]+=cnt[i];
                }
            }else break;
        }
        if(cnt[i]==2)ans++;
    }
    return ans;
}
int id=0;
int dfs(int i,int cnt){
    if(i>=n)return n;
    if(cnt==0){
        return i;
    }
    int idd=lower_bound(x+1,x+n+1,x[i]+d)-x;
    if(idd==id){
        idd--;
    }
    return dfs(idd,cnt-1);
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        if(c==13||c==14){
            id=0;
            for(int i=1;i<=n;i++){
                if(x[i]+d>=x[n]&&x[i]-d<=x[1]){
                    id=i;
                    break;
                }
            }
            int ans=0;
            for(int i=1;i<=n;i++){
                int id1=lower_bound(x+1,x+n+1,x[i]+d)-x,id2=dfs(i,2);
                ans+=max(0ll,id2-id1);
            }
            cout<<ans<<"\n";
            continue;
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            ans+=get(i);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
