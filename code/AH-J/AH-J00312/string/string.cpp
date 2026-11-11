#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
struct node{
    ll d;
    char ch;
}a[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    ll sum=0;
    for(ll i=1;i<=n;i++){
        cin>>a[i].d>>a[i].ch;
        sum+=a[i].d;
    }
    ll l=1,r=n,cnt=0;
    while(l<r){
        if(a[l].d!=0&&a[r].d!=0&&a[l].ch!=a[r].ch)  cnt++;
        a[l].d--;
        a[r].d--;
        if(a[l].d==0)   l++;
        if(a[r].d==0)   r--;
    }
    cout<<cnt;
    /*48分
    string s="";
    for(ll i=1;i<=n;i++){
        cin>>a[i].d>>a[i].ch;
        for(ll j=1;j<=a[i].d;j++)   s=s+a[i].ch;
    }
    ll st=ll(s.size());
    ll cnt=0;
    for(ll i=st/2+(st%2==1);i<st;i++){
        ll j=st-i-1;
        if(s[i]!=s[j])  cnt++;
    }
    cout<<cnt;
    */
    return 0;
}
