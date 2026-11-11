#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll qread(){
	ll rtn=0,fh=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')fh=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		rtn=rtn*10+c-'0';
		c=getchar();
	}
	return fh*rtn;
}
ll n,m;
ll a[500005],s[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		a[i]=qread();
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int l=1,ans=1;
	for(int r=1;r<=n;r++){
		while(a[r]*(r-l)-(s[r-1]-s[l-1])>m)l++;
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
} 

























