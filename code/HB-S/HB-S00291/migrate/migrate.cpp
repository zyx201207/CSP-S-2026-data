#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e6+5;
const ll INF=1e18;

int n; ll d,ans,a[MAXN];

namespace s1{//8pts
    int v,fl=0,cnt=2e9;
    void dfs(int u,int sum){
        if(sum>cnt)return;
        if(fl>2)return;
        if(u>v)return;
        if(u==v){
            if(sum<cnt){
                cnt=sum;
                fl=1;
            }else if(sum==cnt){
                fl++;
            }else{
                return;
            }
        }
        for(int i=u+1;i<=v;i++){
            if(a[i]-a[u]<=d){
                dfs(i,sum+1);
            }
        }
    }
    void main(){
        ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                cnt=2000000000;
                fl=0;
                v=j;
                dfs(i,0);
                if(fl==2)ans++;
            }
        }
        cout << ans << "\n";
    }
}

namespace s2{//16pts
    const int N=305;
    ll dis[N][N],ct[N][N];
    void main(){
        memset(dis,0,sizeof(dis));
        memset(ct,0,sizeof(ct));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=INF;
            }  
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j){
                    dis[i][j]=0;
                    ct[i][j]=1;
                }else if(abs(a[i]-a[j])<=d){
                    dis[i][j]=1;
                    ct[i][j]=1;
                }
            }
        }
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(i==j||i==k||j==k)continue;
                    if(dis[i][j]==dis[i][k]+dis[k][j]){
                        ct[i][j]+=ct[i][k]*ct[k][j];
                    }else if(dis[i][j]>dis[i][k]+dis[k][j]){
                        ct[i][j]=ct[i][k]*ct[k][j];
                    }
                    dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(ct[i][j]==2)ans++;
            }
        }
        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=n;j++){
        //         cout << ct[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        cout << ans/2 << "\n";
    }
}

namespace s3{//8pts B
    void main(){
        cout << 0 << "\n";
    }
}

namespace s4{//8pts A
    void main(){
        if(n==1){
            cout << 0 << "\n";
            return;
        }
        ll dis=a[2]-a[1];
        ll x=d/dis;
        if(x==1){
            cout << 0 << "\n";
            return;
        }
        cout << n-x-1 << "\n";
    }
}

void solve(int c){
    ans=0;
    cin >> n >> d;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    if(n<=300){s2::main();return;}
    if(c==13||c==14){s3::main();return;}
    if(c==11||c==12){s4::main();return;}
    s2::main();
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int c,T; cin >> c >> T;
    while(T--)solve(c);
    return 0;
}