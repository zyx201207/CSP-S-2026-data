#include<bits/stdc++.h>
using namespace std;
using ll=long long;
struct str{
    ll a;
    char b;
}a[200009];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>a[i].a>>a[i].b;
    }
    ll s=0,i=0,j=n-1;
    while(i<j){
        ll m=min(a[i].a,a[j].a);
        a[i].a-=m;
        a[j].a-=m;
        if(a[i].b!=a[j].b)s+=m;
        if(a[i].a==0){
            i++;
        }if(a[j].a==0){
            j--;
        }
    }
    cout<<s;
    return 0;
}
