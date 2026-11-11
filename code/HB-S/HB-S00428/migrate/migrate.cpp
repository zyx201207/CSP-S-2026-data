#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct mig{
    ll dis,num;
};
ll c,t,n,d,a[5005],sum;
mig f[5005][5005];
void connect(ll i,ll j){
    if(f[i][j].dis!=LLONG_MAX||f[i][j].dis==-1) return;
    if(j-i==1&&a[j]-a[i]>d){
        f[i][j].dis=-1;
        return;
    }
    for(ll k=i+1;k<j;k++){
        if(f[i][k].dis!=LLONG_MAX&&f[k][j].dis!=LLONG_MAX&&f[k][j].dis!=-1&&f[i][k].dis!=-1){
            if(f[i][j].dis>f[i][k].dis+f[k][j].dis){
                f[i][j].dis=f[i][k].dis+f[k][j].dis;
                f[i][j].num=1;
            }else if(f[i][j].dis==f[i][k].dis+f[k][j].dis){
                f[i][j].num++;
            }
        }else{
            connect(i,k);
            connect(k,j);
        }
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        sum=0;
        cin>>n>>d;
        for(ll i=1;i<=n;i++){
            cin>>a[i];
            f[i][i].dis=0;
        }
        for(ll i=1;i<=n;i++){
            for(ll j=i+1;j<=n;j++){
                if(a[j]-a[i]<=d){
                    f[i][j].dis=1,f[i][j].num=1;
                }else{
                    f[i][j].dis=LLONG_MAX;
                    f[i][j].num=0;
                }
            }
        }
        for(ll i=1;i<=n;i++){
            for(ll j=i+1;j<=n;j++){
                if(f[i][j].dis!=1&&f[i][j].dis==LLONG_MAX){
                    connect(i,j);
                }
            }
        }
        for(ll i=1;i<=n;i++){
            for(ll j=i+1;j<=n;j++){
                if(f[i][j].num==2){
                    sum++;
                    //cout<<i<<' '<<j<<'\n';
                }
            }
        }
        /*
        for(ll i=1;i<=n;i++){
            for(ll j=i+1;j<=n;j++){
                cout<<f[i][j].dis<<' '<<f[i][j].num<<'\n';
            }
        }
        */
        cout<<sum<<'\n';
    }
    return 0;
}
