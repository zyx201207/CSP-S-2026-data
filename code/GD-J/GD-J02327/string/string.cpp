#include <bits/stdc++.h>

long long s[200001];

int main(){
	std::freopen("string.in","r",stdin);
	std::freopen("string.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0),std::cout.tie(0);
	int n;
	std::cin>>n;
	int a[200001];
	char c[200001];
	for (int i=1;i<=n;i++){
		std::cin>>a[i]>>c[i];
		s[i]=s[i-1]+a[i];
	}
	long long ans=0;
	for (int i=1;i<=s[n]/2;i++){
		int p=std::lower_bound(s+1,s+n+1,i)-s,q=std::lower_bound(s+1,s+n+1,s[n]-i+1)-s;
		if (c[p]!=c[q]) ans++;
	}
	std::cout<<ans<<std::endl;
	return 0;
}

