#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200005],maxn=0,ans;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		if(maxn<a[i]) maxn=a[i];
	}
	if(m==1) 
	{
		cout << maxn;
		exit(0);
	}
	if(m==n)
	{
		ans=a[1];
		for(int i=1;i<=n;i++)
			ans=ans&a[i];
		cout << ans;
		exit(0);
	}
	if(m==2)
	{
		maxn=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(maxn<(a[i]&a[j]))
					maxn=a[i]&a[j];
		cout << maxn;
		exit(0); 
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
