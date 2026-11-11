#include <bits/stdc++.h>
using namespace std;
long long a[200005], dp[200005];
inline long long read(){
	long long s(0), ch=getchar();
	while(ch<'0' || ch>'9') ch=getchar();
	for(;ch>='0' && ch<='9';ch=getchar()) s=(s<<3)+(s<<1)+ch-'0';
	return s;
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n=read(), m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	long long s=1;
	for(int i=1;i<=30;i++){
		dp[0]+=s;
		s<<=1;
	}
	for(int i=1;i<=n;i++){
		int x=min(m, i);
		for(int j=x;j>=1;j--){
			dp[j]=max(dp[j], dp[j-1]&a[i]);
		}
	}
	cout << dp[m];
	return 0;
} 
