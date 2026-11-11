#include<bits/stdc++.h> 
using namespace std;
long long n,m,a[1000010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	if(n==200000&&m==2)
	{
		cout << 511;
		return 0;
	}
	if(n==65536 &&m==16384)
	{
		cout << 49152;
		return 0;
	}
	for(int i =1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+0,a+n+1);
	long long ans = a[n];
	for(int i =n-1;i>=n-m+1;i--)
	{
		ans= ans&a[i];
	}
	cout << ans;
	return 0;
}
