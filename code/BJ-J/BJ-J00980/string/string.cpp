#include<iostream>
typedef long long ll;
using namespace std;
char c[200005],fc[200005];
ll a[200005],lef[200005],righ[200005],fa[200005],fleft[200005],fright[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ll n,sum=0,l=1,r=1;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        sum+=a[i];
        lef[i]=righ[i-1]+1;
        righ[i]=lef[i]+a[i]-1;
    }
    for(int i=1;i<=n;i++){
        fa[i]=a[n-i+1];
        fc[i]=c[n-i+1];
        fleft[i]=fright[i-1]+1;
        fright[i]=fleft[i]+fa[i]-1;
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        while(r<=n&&fleft[r]<=righ[i]){
            ll nll=max(fleft[r],lef[i]),nrr=min(righ[i],fright[r]);
            //cout<<i<<" "<<r<<" "<<c[i]<<" "<<fc[r]<<" "<<nll<<" "<<nrr<<endl;
            if(fc[r]!=c[i]){
                ans+=nrr-nll+1;
            }
            r++;
        }
        r--;
    }
    cout<<ans/2<<endl;
    return 0;
}
