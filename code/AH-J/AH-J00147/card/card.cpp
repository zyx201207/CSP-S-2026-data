#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500005],b[500005],c[300005];
int chk(ll n,ll g){
    for(int i=1;i<=n;i++){
        if(b[i]==g){
             //cout<<"#";
            return i;
        }
    }
    return 0;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,m,i,j,k,s=1,x=0;
    cin>>n>>m;
    for(i=1;i<=n;i++){
        cin>>a[i];
    }
    for(i=1;i<=n;i++){
        x=0;
        for(j=i;j<=n;j++){
            ll asas=chk(x,a[j]);
            if(asas!=0){
                x=asas-1;
            }
            x++;
            b[x]=a[j];
        }
        for(j=1;j<=x;j++){
                //cout<<b[j]<<endl;
            c[b[j]]++;
        }
        //cout<<endl;
    }
    for(i=1;i<=m;i++){
        cout<<c[i]<<' ';
    }
    return 0;
}
