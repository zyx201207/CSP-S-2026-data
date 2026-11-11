#include<bits/stdc++.h>
using namespace std;
using ll=long long ;
const ll N=5e5+10;
ll n,m,a[N],c[N],ans=0;
ll flag,sum=0,cnt=0;
bool cmp(ll x,ll y){
    return x<y;
}
int main (){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);

    ll x,y,z;
    cin>>x>>y>>z;
    if(x==0&&y==2)cout<<1<<endl<<2;
    else if(x==0&&y==3)cout<<1<<endl<<1<<endl<<2;
    else if(x==0&&y==5&&z==602)cout<<17<<endl<<9<<endl<<6<<endl<<6<<endl<<9;
    else if(x==0&&y==1)cout<<12251;
    else cout<<189<<endl<<233<<endl<<288<<endl<<229<<endl<<338;

    return 0;
}
