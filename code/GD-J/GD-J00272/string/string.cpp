#include <bits/stdc++.h>
using namespace std;
constexpr int N=2e5+5;
int n,a[N];
unsigned long long cnt;
char c[N];
string ans;
int gcd(int a,int b){
	if (b==0) return a;
	return gcd(b,a%b);
}
int arrgcd(int a[]){
	int ans=a[0];
	for (int i=1;i<n;++i) ans=gcd(ans,a[i]);
	return ans;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;++i) scanf("%d %c",&a[i],&c[i]);
	const unsigned long long gg=arrgcd(a);
	for (int i=1;i<=n;++i){
		a[i]/=gg;
		while (a[i]--) ans.push_back(c[i]);
	}
	int len=ans.size();
	for (int i=0,j=len-1;i<j;++i,--j){
		if (ans[i]!=ans[j]){
			ans[j]=ans[i];
			++cnt;
		}
	}
	printf("%llu",cnt*gg);
	return 0;
}

