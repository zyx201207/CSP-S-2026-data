#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct stu{
    ll g;
    char m;
}a[200000+10];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ll n;
    cin>>n;
    ll ans=0,sum=0;
    for(ll i=1;i<=n;i++){
        cin>>a[i].g>>a[i].m;
        ans+=a[i].g;
    }
    string s;
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=a[i].g;j++){
                s+=a[i].m;
            }
        }
        ll len=s.size();
        for(ll i=0;i<len;i++){
            if(i==len-i-1){
                break;
            }
            if(s[i]!=s[len-i-1]){
                sum++;
            }
        }
    cout<<sum;
    return 0;
}

