/*
Part of my heart was left behind that day
I remember every time I smell the rain
Asking myself, what atonoment means?
Why not this world takes me away to heaven?

Pierces my heart, PETRICHOR
Causes me grief, PETRICHOR

Rain penestrates the core of my body
And its coldness stirs up endless my regrets
In search of blue skies, I lost my way
How far will the dark and damp journey continue?

I will prey forever even if it never ends...

-- Petrichor //void (Mournfinale)//
*/
/*
===18:28===
~8pts?
enough...
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ul;
typedef unsigned int sx;
ll read(){
    ll a=0;bool f=0;char c=getchar();
    while(c>'9'||c<'0'){if(c=='-'){f=1;}c=getchar();}
    while(c<='9'&&c>='0'){a=a*10+c-'0';c=getchar();}
    return (f?-1:1)*a;
}
ll a[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ll c=read(),T=read();
    while(T--){
        ll n=read(),m=read();
        for(ll i=1;i<=n;i++){a[i]=read();}
        ll dlt=a[2]-a[1];
        if((n-(m/dlt)*2+1<0)||(dlt>=m)){cout<<"0\n";}
        else{cout<<n-(m/dlt)*2+1<<"\n";}
    }
    return 0;
}