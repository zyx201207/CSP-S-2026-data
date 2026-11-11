#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n, ans=0, mans=0;
long long m, a[N];
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin>>n>>m;
	for(int i=1; i<=n; ++i) 
		cin>>a[i];
	sort(a+1, a+n+1);
	long long sum=0, last=a[1], tail=1; 
	for(int i=0; i<n; ++i) {
		sum+=(a[i+1]-last)*(i-tail+1);
		last=a[i+1];
		if(sum<=m)
			ans++;
		else {
			while(sum>m) {
				sum-=last-a[tail];
				tail++;
				if(ans)
					ans--;
			}
			ans++;
		}
		mans=max(mans, ans);
	}
	cout<<mans;
	return 0;
} 
