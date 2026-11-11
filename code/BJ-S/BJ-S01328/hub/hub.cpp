#include<bits/stdc++.h>
#define lowbit(i) i&(-i)
using namespace std;
const int N=2e6+11;
int c,t,n,k,u,lg[5001],have[N],v2,have2[N],ans=0;
vector<int> v[N];
void d(int x,int f){
    if(have[x]!=1)return ;
    have2[x]=1;
    for(int i=0;i<v[x].size();i++){
        if(v[x][i]==f)continue;
        d(v[x][i],x);
    }
}
void dfs(int x,int f,int step){
    if(have[x])ans=max(ans,step);
    for(int i=0;i<v[x].size();i++){
        if(v[x][i]==f)continue;
        dfs(v[x][i],x,step+1);
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    for(int i=0;i<=10;i++){
        lg[(1<<i)]=i;
    }
    while(t--){
        cin>>n>>k;
        for(int i=1;i<n;i++){
            cin>>u>>v2;
            v[u].push_back(v2);
            v[v2].push_back(u);
        }
        int maxn=(1<<n)-1,minn=2e9+11;
        for(int i=1;i<=maxn;i++){
            memset(have,0,sizeof(have));
            memset(have2,0,sizeof(have2));
            int r=i,cnt=0;
            while(r!=0){
                cnt++;
                have[lg[lowbit(r)]+1]=1;
                r-=lowbit(r);
            }
            if(cnt!=k)continue;
            int cnt2,f2=0;
            for(int i=1;i<=n;i++){
                if(have[i]==1){
                    if(cnt2>=2&&have2[i]==0){
                        f2=1;
                        break;
                    }
                    d(i,0);
                    cnt2++;
                }
            }
            if(f2)continue;
            ans=0;
            for(int i=1;i<=n;i++){
                dfs(i,0,0);
            }
            //cout<<1;
            minn=min(ans,minn);
        }
        cout<<minn<<"\n";
    }
    return 0;
}
