#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define il inline
#define fr(i,a,b) for(int i=a;i<=b;++i)
#define Fr(i,a,b) for(int i=a;i>=b;--i)
il ll rd(){
	ll x=0,f=1; char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-1;
	for(;isdigit(ch);ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
	return x*f;
}
const int N=5e5+5;
int n,ans;
ll a[N],m,s[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    n=rd(),m=rd();
    fr(i,1,n) a[i]=rd();
    sort(a+1,a+n+1);
    fr(i,1,n) s[i]=s[i-1]+a[i];
    fr(i,1,n){
		int l=1,r=i,mid,d=i;
		while(l<=r){
			mid=(l+r)>>1;
			if((i-mid+1)*a[i]-s[i]+s[mid-1]<=m) d=mid,r=mid-1;
			else l=mid+1;
		} ans=max(ans,i-d+1);
	} cout<<ans;
    return 0;
}
