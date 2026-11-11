#include<bits/stdc++.h>
using namespace std;
int ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	vector<long long> a;
	cin >> n >> m;
	for(int i=0;i<n;i++)
	{
		long long x;
		cin >> x;
		a.push_back(x);
	}
	if(m==0)
	{
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
				if(a[i]==a[j])
					ans++;
		cout << ans;
		return 0;
	}
	int t=abs(abs(a[1])-abs(a[0]));
	//cout << t << '\n';
	for(int i=n;i>=0;i--)
	{
		if(m-(n-i)*t>=0)
		{
			m-=(n-i)*t;
			ans++;
		}
		else
			break;
	}
	cout << ans;
	return 0;
}
