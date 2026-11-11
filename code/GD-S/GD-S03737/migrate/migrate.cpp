#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,d,q,a[1000],num = 0,b[1000];
void island(int w,int s,int e)
{
	e++;
	if(s == d)
	{
		if(s == e)
		{
			return;
		}
		island(w,s,e);
	}
	else
	{
		island(w,s + 1,e);
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	scanf("%d%d",&c,&t);
	for(int i = 0;i < t;i++)
	{
		scanf("%d%d",&n,&d);
		for(int j = 0;j < n;j++)
		{
			scanf("%d",&q);
			a[j] = q;
			q = j;
		}
		for(int j = 0;j < q;j++)
		{
			island(1,q,j);
		}
		b[i] = num;
		num = 0;
	}
	for(int i = 0;i < t;i++)
	{
		cout << b[i] << endl;
	}
	return 0;
}
