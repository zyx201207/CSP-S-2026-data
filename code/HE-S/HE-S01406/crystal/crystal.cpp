#include<bits/stdc++.h>
using namespace std;

int n;
long long m, maxn;
int a[100010], c[100010];

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n>=100000) n = 100000;
	sort(a+1, a+1+n);
	for(int i=1;i<=n;i++)
	{
		c[i] = a[i+1]-a[i];
		long long cnt=1, ans=0;
		
		for(int j=i-1;j>=1;j--)
		{
//			cout<<"___"<<ans+ans+c[j]<<endl;
			if(ans+ans>m-c[j]) break;
			cnt++;
			ans += ans+c[j];
//			cout<<ans<<" ";
		}
//		cout<<cnt<<endl;
		maxn = max(maxn, cnt);
	}
	
	cout<<maxn;
	return 0;
}
