#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
const int N=2e6+5;
using namespace std;
int c,t,n,dis[N],bot[N];
ll d,a[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>t;while(t--){
        cin>>n>>d;ll ans=0;
        for(int i=1;i<=n;i++)cin>>a[i];
        if(c<=10)for(int u=1;u<=n;u++){
            dis[u]=0,bot[u]=1;
            for(int i=u+1;i<=n;i++)dis[i]=n+1;
            for(int i=u;i<=n;i++){
                //cout<<u<<" "<<i<<" "<<dis[i]<<" "<<bot[i]<<"\n";
                if(i!=u&&bot[i]==2)ans++;if(bot[i]>2)bot[i]=3;
                for(int j=i+1;a[j]-a[i]<=d&&j<=n;j++){
                    if(dis[i]+1<dis[j])dis[j]=dis[i]+1,bot[j]=bot[i];
                    else if(dis[i]+1==dis[j])bot[j]+=bot[i];
                }
            }
        }else if(c==11||c==12){
            ll lab=d/(a[2]-a[1]);
            if(lab==0||lab==1)ans=0;
            else ans=max(0ll,n-2*lab+1);
        }else{
            int j=1;
            for(int i=1;i<=n;i++){
                while(a[j]-a[i]<=d&&j<=n)j++;
                ans+=n-j+1;
            }
        }cout<<ans<<"\n";
    }
    return 0;
}
