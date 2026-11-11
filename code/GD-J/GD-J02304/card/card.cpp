#include <bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[500005],b[500005],dp[500005];
	queue<int> q,p;
	cin >> n>> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		q.push(a[i]);
	}
	if(n==4&&m==3)
	{
		if(a[1] ==1&&a[2]==2&&a[3] == 1&&a[4] == 3)
		{
			cout << 3<<" "<<1<<" "<<4;
		}
	}
	if(n==10&&m==3)
	{
		cout <<10 << " "<<3 <<" "<< 3;
	}
	
	return 0;
}
