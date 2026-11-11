#include<bits/stdc++.h>

using namespace std;

int main()
{
	freopen("and.in",'r',stdin);
	freopen("and.out",'w',stdout);
	
	int d[100000];
	int n,m,max=0,cnt=2,r1,r2,ma=0;
	cin >> n >> m;
	for(int i=0;i<n;i++)
	{
		cin >> d[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(max<(d[i]&d[j]))
			{
				max = d[i]&d[j];
				r1 = i;
				r2 = j;
			}
		}
	}
	for(int m=r1;m<n;m++)
	{
		d[m] = d[m+1];
	}
	for(int m=r2-1;m<n;m++)
	{
		d[m] = d[m+1];
	}
	while(cnt<m)
	{
		cnt++;
		for(int i=0;i<n;i++)
		{
			if(ma<(d[i]&max))
			{
				ma = d[i]&max;
				r1 = i;
			}
		}
		for(int m=r1;m<n;m++)
		{
			d[m] = d[m+1];
		}
		max = ma;
	}
	cout << max;
	return 0;
}
