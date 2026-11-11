#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200010];
char ch[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ll n,cnt=0;
    string s,t;
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)cin>>a[i]>>ch[i];
    ll g=a[1];
    for(int i=2;i<=n;i++)g=__gcd(g,a[i]);
    for(int i=1;i<=n;i++)a[i]/=g;
    for(int i=1;i<=n;i++)s+=string(a[i],ch[i]);
    t=s;
    reverse(s.begin(),s.end());
    for(int i=0;i<s.size();i++){
        if(s[i]!=t[i]){
            s[i]=t[i];
            cnt++;
            t[s.size()-1-i]=s[i];
        }
    }
    cout<<cnt*g;
    return 0;
}
