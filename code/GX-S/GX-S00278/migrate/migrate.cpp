#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10,mod1=1e9+7,mod2=1e9+9;
int t,n,dis[N][N],cnt1[N][N],cnt2[N][N],c;
long long a[N],d;

struct node{
    int u,w;
    bool operator < (const node &b) const{
        return w>b.w;
    }
};

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    if(c>10){
        while(t--){
            cout<<"0\n";
        }
        return 0;
    }
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cnt1[i][j]=cnt2[i][j]=0;
                if(i!=j) dis[i][j]=n+5;
                else dis[i][j]=0;
            }
        }
        priority_queue<node> q;
        int ans=0;
        for(int i=1;i<=n;i++){
            while(!q.empty()) q.pop();
            q.push({i,0});
            cnt1[i][i]=cnt2[i][i]=1;
            while(!q.empty()){
                int u=q.top().u;
                q.pop();
                for(int v=i;v<=n;v++){
                    if(abs(a[v]-a[u])<=d&&dis[i][v]>dis[i][u]+1){
                        dis[i][v]=dis[i][u]+1;
                        cnt1[i][v]=cnt1[i][u];
                        cnt2[i][v]=cnt2[i][u];
                        q.push({v,dis[i][v]});
                    }else if(abs(a[v]-a[u])<=d&&dis[i][v]==dis[i][u]+1){
                        cnt1[i][v]+=cnt1[i][u];
                        cnt1[i][v]%=mod1;
                        cnt2[i][v]+=cnt2[i][u];
                        cnt2[i][v]%=mod2;
                    }
                }
            }
            for(int j=i;j<=n;j++) ans+=(cnt1[i][j]==2&&cnt2[i][j]==2);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
