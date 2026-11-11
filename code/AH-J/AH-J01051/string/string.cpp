#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define ffor(i,a,b) for(ll i=(a);i<=(b);++i)
#define roff(i,a,b) for(ll i=(a);i>=(b);--i)
const ll N=200010;
struct node{
    ll x;
    char c;
}a[N];
ll n,l;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    ffor(i,1,n) cin>>a[i].x>>a[i].c;
    string s;
    ffor(i,1,n) ffor(j,1,a[i].x) s+=a[i].c;
    l=s.size();
    string s1;
    ffor(i,0,(l+1)/2-1) s1+=s[i];
    roff(i,l/2-1,0) s1+=s1[i];
    string s2;
    roff(i,l-1,l/2) s2+=s[i];
    ffor(i,(l+1)/2,l-1) s2+=s[i];
    ll c1=0,c2=0;
    ffor(i,0,l-1) if(s[i]!=s1[i]) c1++;
    ffor(i,0,l-1) if(s[i]!=s2[i]) c2++;
    cout<<min(c1,c2);
    return 0;
}
