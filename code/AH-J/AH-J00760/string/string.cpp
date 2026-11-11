#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[200010],ans=0;
char ch[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>a[i]>>ch[i];
    }
    for(ll i=1;i<=n/2;i++){
        ll j=n-i+1;
        if(a[i]!=a[j]&&ch[i]==ch[j]&&i+1!=j)   ans+=abs(a[i]-a[j]);
        else if(a[i]==a[j]&&ch[i]!=ch[j])   ans+=a[j];
        else if(a[i]!=a[j]&&ch[i]!=ch[j])   ans+=a[i];
    }
    cout<<ans;
    return 0;
}
