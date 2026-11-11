#include<bits/stdc++.h>
using namespace std;
const int N = 200010;
int num[N];
char a[N];
int n;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++) cin >> num[i] >> a[i];
	int l = 1,r = n;
	long long ans = 0;
	while(l < r)
	{
		int ch = min(num[l],num[r]);
		if(a[l] != a[r])
		{
			ans += ch;
		}
		num[l]-=ch;
		num[r]-=ch;
		if(!num[l]) l++;
		if(!num[r]) r--;
	}
	cout << ans;
	return 0;
}
