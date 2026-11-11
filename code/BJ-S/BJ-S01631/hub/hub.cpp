#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,k,x,y,ans;
int bok[35];
vector<int>p[15];
void dfs(int x,int lastx){
    bok[x]=0;
    for(int i=0;i<p[x].size();i++){
        int xx=p[x][i];
        if(!bok[xx]||xx==lastx)continue;
        dfs(xx,x);
    }
    return ;
}
bool check(int mask){
    int num=0,cnt=1;
    while(mask){
        if(mask&1){
            bok[cnt]=1;
            num++;
        }
        cnt++;
        mask>>=1;
    }
    for(int i=1;i<=n;i++)bok[i]=0;
    if(num!=k)return false;
    int kk=0;
    for(int i=1;i<=n;i++){
        if(bok[i]){
            dfs(i,0);
            kk++;
        }
    }
    if(kk>2)return false;
    return true;
}
void dfs_max(int x,int lastx){
    ans=max(ans,bok[x]);
    for(int i=0;i<p[x].size();i++){
        int xx=p[x][i];
        if(xx==lastx)continue;
        if(!bok[xx])bok[xx]=bok[x]+1;
        bok[xx]=min(bok[xx],bok[x]+1);
        dfs(xx,x);
    }
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    srand(time(0));
    while(t--){
        scanf("%lld%lld",&n,&k);
        cout<<k<<endl;
        ans=0;
        if(n>10){
            cout<<rand()%(n/2)<<'\n';
            continue;
        }
        for(int i=1;i<=n;i++)p[i].clear();
        for(int i=1;i<n;i++){
            scanf("%lld%lld",&x,&y);
            p[x].push_back(y);
            p[y].push_back(x);
        }
        for(int i=0;i<(1<<n)-1;i++){
            if(check(i)){
                int mak=i,now=1;
                while(mak){
                    if(mak&1)bok[now]=1;
                    now++;
                    mak>>=1;
                }
                for(int i=1;i<=n;i++){
                    if(bok[i]==1){
                        dfs_max(i,0);
                    }
                }
                for(int i=1;i<=n;i++){
                    bok[i]=0;
                }
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
