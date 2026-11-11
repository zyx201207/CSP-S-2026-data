#include <bits/stdc++.h>
using namespace std; 
int a[10000010];
int b[10000010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,cnt=0;
	cin >> n >> m;
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
		b[i]=a[i];
	}
	sort(a+1,a+n+1);
	for(int i=0;i<m;i++)
	{
		if(b[m]==i+1) cout << m << " ";
		else
		{
			for(int j=0;j<n;j++)
			{
				if(a[j]==i+1) cnt++;
				if(a[j]!=i+1&&a[j]-i+1>0) break;
			}
			cout << cnt << " ";
		}
	}
	return 0;
}
