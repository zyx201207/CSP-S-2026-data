#include<bits/stdc++.h>
using namespace std;
long long n,a[200005];
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	long long l = 0;
	string wh = "";
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i] >> c[i];
		l+=a[i];
		while(a[i]--)
			wh+=c[i];
	}
	long long ans = 0;
	int left=0,right=l-1;
	while(left<=right)
	{
		if(wh[left]!=wh[right])
			ans++;
		left++;
		right--;	
	}
	cout << ans;
	return 0;
}
