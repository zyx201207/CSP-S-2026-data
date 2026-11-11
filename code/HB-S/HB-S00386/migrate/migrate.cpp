#include <iostream>
using namespace std;
long long c,t,n,d,x[5005],num,m,f;
void dfs(int a,int b,int s,int z)
{
	if(a==b)
	{
		m++;
		if(!f)	f=1;
		return;
	}
	if(s+1==z)	
	{
		if(x[b]-x[a]<=d)	dfs(b,b,s+1,z);
		return;
	}
	for (int i = a+1;i <= b;i++)
	{
		if(x[i]-x[a]<=d)	dfs(i,b,s+1,z);
		else    break;
	}
	return;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	if(c==11||c==12)
	{
		for (int i = 1;i <= t;i++)
		{
			cin >> n >> d;
			for (int j = 1;j <= n;j++)	cin >> x[j];
			if(d>=2*(x[2]-x[1]))
			{
				num=n-3;
			}
			cout << num << "\n";
			num=0;
		}
		return 0;
	}
	for (int i = 1;i <= t;i++)
	{
		cin >> n >> d;
		num=0;
		for (int j = 1;j <= n;j++)	cin >> x[j];
		for (int j = 1;j <= n-2;j++)
		{
			for (int l = j+3;l <= n;l++)
			{
				if(x[l]-x[j]<=d)	continue;
				for (int v = 2;v <= l-j-1;v++)
				{
					f=0;
					m=0;
					dfs(j,l,0,v);
					if(m==2)	num++;
					if(f)	break;	
				}
			}
		}
		cout << num << "\n";
	}
	return 0;
}
