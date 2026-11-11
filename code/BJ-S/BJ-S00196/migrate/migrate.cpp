#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5005;
int n,d,a[N],vis[N],ans[N],cnt;
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t,c;
    cin>>c>>t;
    while(t--){
        cnt=0;
        memset(a,0,sizeof a);
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<n;i++){
            memset(vis,-1,sizeof vis);
            memset(ans,0,sizeof ans);
            queue<int> q;
            q.push(i);
            vis[i]=1;
            while(q.size()){
                int k=q.front();q.pop();
                int kk=k+1;
                while(kk<=n && a[kk]-a[k]<=d){
                    if(vis[kk]==vis[k]+1) ans[kk]++;
                    else if(kk<=n && vis[kk]==-1){
                        vis[kk]=vis[k]+1;
                        ans[kk]=1;
                        q.push(kk);
                    }
                    kk++;
                }
                //cout<<k<<endl;
            }
            for(int j=i;j<=n;j++) if(ans[j]==2) cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
