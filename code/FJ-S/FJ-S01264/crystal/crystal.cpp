#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,m;
ll a[500010],b[500010];

ll read(){
	char ch=getchar();
	ll f=1,x=0;
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x*=10;
		x+=(ll)(ch-'0');
		ch=getchar();
	}
	return f*x;
}

ll ef(ll o){
	
	ll L=o,R=n+1,mid=(L+R)/2;
	
	while(L+1<R){
		ll x=a[mid]*(mid-o+1)-b[mid]+b[o-1];
		if(x>m){
			R=mid;
		}
		if(x<=m){
			L=mid;
		}
		mid=(L+R)/2;
	}
	return L-o+1;
	
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=a[i]+b[i-1];
	}
	
	ll ans=-1;
	for(int i=1;i<=n;i++){
		ans=max(ans,ef(i));
	}
	cout<<ans;
	return 0;
}