#include<bits/stdc++.h>
using namespace std;

int n;
long long m,a[500005],s[500005],ans;

int bin(long long l,long long r){
	if(l>r)	return 0;
	if((r-l+1)<=ans)	return ans;
	long long e=(r-l)*a[r]-s[r-1]+s[l-1];
	if(e<=m){
		ans=max(ans,r-l+1);
		return r-l+1;
	}else{
		return max(bin(l+1,r),bin(l,r-1));
	}
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	cout<<bin(1,n);
	return 0;
}
