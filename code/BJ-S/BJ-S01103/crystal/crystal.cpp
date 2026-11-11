#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005],ans=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    ll mi,arr;
    if(n%2==0){
        mi=n/2;
        arr=a[mi];
    }else{
        mi=n/2+1;
        arr=a[mi];
    }
    for(ll i=mi;i<=n;i++){
        if(a[i]==arr)ans++;
    }
    for(ll i=mi-1;i>=0;i--){
        ll j=arr-a[i];
        if(m>=j){
            m-=j;
            ans++;
        }
        else break;
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
