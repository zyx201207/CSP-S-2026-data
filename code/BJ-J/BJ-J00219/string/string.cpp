#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=2e5+5;
struct node{
    LL w;
    char d;
}rg[N];
LL n,l,r,ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    l=1;r=n;
    for(int i=1;i<=n;i++)cin>>rg[i].w>>rg[i].d;
    while(l<r){
        LL k=min(rg[l].w,rg[r].w);
        if(rg[l].d!=rg[r].d)ans+=k;
        rg[l].w-=k;rg[r].w-=k;
        if(!rg[l].w)l++;
        if(!rg[r].w)r--;
    }
    cout<<ans<<'\n';
    return 0;
}
