#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,t;
ll n,d;
ll x[2000005];
ll dis[505][505];
ll vis[505][505];
long long fl(){
    ll ans=0;
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dis[i][k]+dis[k][j]==dis[i][j])
                    vis[i][j]++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(vis[i][j]==4&&abs(i-j)>2){
                ans++;
            }
        }
    }
    return ans/2;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        if(c==13||c==14){//B
            cout<<"0"<<endl;
        }
        else if(n<=2){
            cout<<"0"<<endl;
        }
        else if(c==11||c==12){//A
            ll k=x[2]-x[1];
            ll a=d/k;
            //cout<<a<<" "<<d<<" "<<k<<" ";
            if((n>2*a-1)&&a>1) cout<<n-(2*a-1)<<endl;
            else cout<<"0"<<endl;
        }
        else if(n<=300){
            memset(dis,0x3f,sizeof(dis));
            memset(vis,0,sizeof(vis));
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(i!=j&&abs(x[i]-x[j])<=d) dis[i][j]=1;
                    else if(i==j) dis[i][j]=0;
                }
            }
            cout<<fl()<<endl;
        }

    }
    return 0;
}
