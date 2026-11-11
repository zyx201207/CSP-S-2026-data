#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
typedef long long ll;
ll read(){
	ll s=0;int f=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)) s=(s<<1)+(s<<3)+(ch^48),ch=getchar();
	return s*f;
}
ll n,m,a[N],s[N];
int ans;
int ff(int pos){
	int l=1,r=pos;
	while(l<r){
		int mid=(l+r)>>1;
		if(a[pos]*(pos-mid)-(s[pos-1]-s[mid-1])<=m) r=mid;
		else l=mid+1;
	}
	return l;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int pos=ff(i);
		ans=max(ans,i-pos+1);
	}
	cout<<ans;
}
/*5 8
-3 -1 2 2 7*/
