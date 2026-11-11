#include <bits/stdc++.h>
#define int long long
constexpr int N = 2e5 + 5;
int n, a[N];
 char c[N];
 std::string s;
void solve () {
	std::cin>>n;
	s+=' ';
	for(int i=1;i<=n;i++){
		std::cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	int ans=0;
	for(int i=1;i<=(s.size()/2);i++){
		if(s[i]!=s[s.size()-i])ans++;
	}
//	for(int i=n;i;i--)suf[i]=suf[i+1]+a[i],s[n-i+1]=suf[i];
//	int ans=0,mid=pre[n]+1>>1;
//	for(int i=1;i<=n;i++)std::cout<<pre[i]<<' '<<s[i]<<'\n';
//	for(int i=1,j=0;i<=n&&j<=n;i++){
//		if(pre[i]>pre[j])
//		std::cout<<i<<'\n';
//		while (j<=n&&s[j] <= pre[i]) {
//			std::cout<<j<<'\n';
//			if(s[j] >= mid) {
//				ans+=(c[i]==c[n-j+1])*(mid-s[j-1]+1);
//			}else ans+=(c[i]==c[n-j+1])*a[j];
//			j++;
//		}
//	}
	std ::cout<<ans;
}

signed main () {
	freopen ("string.in", "r", stdin);
	freopen ("string.out", "w", stdout);
	std :: ios :: sync_with_stdio (false), std :: cin.tie (0), std :: cout.tie (0);
//	int TTT; std :: cin >> TTT; while (TTT --)
	solve ();

	return 0;
}

