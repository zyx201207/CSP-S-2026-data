#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
long long n,m,a[MAXN],s[MAXN];
int main(){
	std::ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	long long l=1,r=1,cot=0,sub=0,ans=0;
	while (l<=r and r<=n){
		while (l+1<=r and cot>m){
			l++,cot-=(a[r]-a[l]);
		}
		ans=max(ans,r-l+1);
		r++,cot=cot+(a[r]-a[r-1])*(r-l);
	}
	cout<<ans;
	return 0;
} 

// 能量只加不减 

/*
5 5
2 1 2 4 8 9

5 8
-3 -1 2 2 7
*/
