#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200005];
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        cin>>c[i];
    }
    ll sum=0;
    for(int i=1;i<=n;i++)sum+=a[i];
    sum/=2;
    int i=1,j=n;
    ll ans=0;
    while(sum){
        if(sum>=a[i])sum-=a[i];
        else{
            a[i]=sum;
            sum=0;
        }
        while(a[i]){
            if(a[i]>=a[j]){
                ans+=(c[i]!=c[j])*a[j];
                a[i]-=a[j];
                j--;
            }else{
                ans+=(c[i]!=c[j])*a[i];
                a[j]-=a[i];
                a[i]=0;
            }
        }
        i++;
    }
    cout<<ans;
    return 0;
}