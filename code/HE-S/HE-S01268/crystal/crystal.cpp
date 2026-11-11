#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=5e5+7;
ll a[maxn],ans=-1e9,n,m;
ll read(){
	ll f=1,s=0;
	char c=getchar();
	if(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		s=s*10+c-'0';
		c=getchar();
	}
	return f*s;
}
ll Sigm(int u,int v){
	ll s=0;for(;u<=v;u++){
		s+=a[u];
	}
	return s;
}
ll Max(int u,int v){
	ll ans=-1e9;
	for(u;u<=v;u++) ans=max(ans,a[u]);
	return ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();
	m=read();
	for(ll i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+1+n);
	ll p=0;
	for(ll i=1;i<=n;i++){
		if(i+ans-1>n) break;
		if(i>=n-ans+2) break;
		ll sum=Sigm(i,i+p),aim=Max(i,i+p+1);
		while(1){
			if(aim*(p+1)-sum>m) break;
			sum=Sigm(i,i+p+1),aim=Max(i,i+p+1);
			if(i+p>n||aim*(p+2)-sum>m) break;
			p++;
		}
		ans=max(ans,p+1);
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
