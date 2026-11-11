#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=1e5+5;
LL n,a[N],l,r,L,ans,u,v,x,y;char ch[N];
LL t(LL p,LL q){
	return max(p,q)-abs(p-q);
}int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>ch[i];L+=a[i];
    }l=1;r=L;u=1;v=n;
    while(l<=r){
		LL R=L-r+1;
        if(l==L-r+1){
            l+=a[u];r-=a[v];
            if(ch[u]!=ch[v]) ans+=t(a[u],a[v]);
            u++;v--;
        }else if(l>=R){
            if(ch[u-1]!=ch[v]) ans+=t(a[v],l-R);
            r-=a[v];
            v--;
        }else{
            if(ch[u]!=ch[v+1]) ans+=t(a[u],R-l);
            l+=a[u];
            u++;
        }
    }cout<<ans;
    return 0;
}
