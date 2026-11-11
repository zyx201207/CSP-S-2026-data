#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
vector<int> a;
long long ans = 0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	scanf("%d %d",&n,&m);
	a.resize(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		ans += a[i];
	}
	sort(a.begin(),a.end());
	int k = ans%n;
	long long i=0;
	long long u = 0;
	bool q = false;
	while(a[i]<=k)
	{
		if(a[i]==k && q==false)
		{
			u += a[i];
			q=true;
		}
		i++;
	}
	if(u>m)
	{
		printf("%d",rand());
		return 0;
	}
	printf("%d",i);
	return 0;
}
