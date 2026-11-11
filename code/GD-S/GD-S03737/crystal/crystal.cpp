#include<bits/stdc++.h>
using namespace std;
int n,m,q,num = 0;
int a[1000]; 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i = 0;i < n;i++)
	{
		scanf("%d",&q);
		a[i] = q;
	}
	q = m;
	for(int i = 0;i < n;i++)
	{
		for(int j = 0;j < n;j++)
		{
			if(q == 0)
			{
				break;
			}
			if(a[i] == a[j])
			{
				num++;
				break;
			}
			a[i]++;
			q--;
		}
		if(q == 0)
		{
			break;
		}
	}
	cout << num;
	return 0;
} 
