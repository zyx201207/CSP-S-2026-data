#include <bits/stdc++.h>
using namespace std;
int main()
{
	
	int m = 0,n = 0,c = 0,num = 0;
	cin>>m>>n;
	int v[m];
	for(int i = 0;i < m;i++)
	{
		cin>>v[i]; 
	 }
	for(int i = 0;i < m;i++)
	{
		for(int j = 0;j < m;j++)
		{
			if(v[i] < v[j])
			{
				c = v[j];
				v[j] = v[i];
				v[i] = c;
			}
		}
	}

	num = v[m - 1];
	for(int i = m -1;i >= m - n;i--)
	{
		num &= v[i];
	}
	cout<<num;
	return 0;
}
