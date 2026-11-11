/*#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
long long n,m,a[maxn],ms[maxn],f[maxn],min1=119324583425,mini,tot=0;
int main(){
    cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i+tot<n;i++){
        while(a[i+tot+1]==a[i+tot]){
            f[i]++;
            tot++;
        }
        ms[i]=a[i+tot+1]-a[i+tot];
    for(int i=1;i<n;i++){
        if(ms[i]*f[i]*f[mini]<min1&&ms[i]*f[i]<=m){
            mini=i;
            min1=ms[i]*f[i];
        }
    }
    if(min1==119324583425){
        cout<<1;
        return 0;
    }
    m-=min1;

    return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
long long n,m,a[maxn],ms,ans=1,sum=0;
int main(){
    cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    ms=a[2]-a[1];
    while(m>=sum){
        sum=ms*ans+sum;
        ans++;
    }
    cout<<ans-1;
    return 0;
}
