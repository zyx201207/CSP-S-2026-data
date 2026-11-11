#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5e3+5;
const int INF=4e18;
int c,T;
int n,d,a[maxn],dis[maxn][maxn],cnt[maxn][maxn];
int Abs(int a,int b){
    return a>b?a-b:b-a;
}
void solve(){
    cin>>n>>d;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        if(Abs(a[i],a[1])<=d&&Abs(a[i],a[n])<=d){
            cout<<0<<'\n';
            return;
        }
    }
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=n;j++)dis[i][j]=INF,cnt[i][j]=0;
	}
    for(int i=1;i<=n;i++)dis[i][i]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)continue;
            if(Abs(a[i],a[j])<=d)dis[i][j]=1,cnt[i][j]=1;
        }
    }
    for(int k=1;k<=n;k++){
        for(int u=1;u<=n;u++){
            for(int v=1;v<=n;v++){
                if(u==v&&u==k)continue;
                if(dis[u][v]>dis[u][k]+dis[k][v]){
                    dis[u][v]=dis[u][k]+dis[k][v];
                    cnt[u][v]=cnt[u][k]*cnt[k][v];
                }
                else if(dis[u][v]==dis[u][k]+dis[k][v]){
                    cnt[u][v]+=cnt[u][k]*cnt[k][v];
                }
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(cnt[i][j]==2)ans++;
        }
    }
    cout<<ans/2<<'\n';
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>T;
    while(T--)solve();
    return 0;
}
/**/
