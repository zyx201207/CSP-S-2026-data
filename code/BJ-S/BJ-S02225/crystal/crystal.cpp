#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,a;
	int max = 1,min= 100,aver = 0;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		if(a>max)
		{
			max = a;
		}
		if(a<min)
		{
			min = a;
		}
		m++;
	}
	aver = (max+min)/2;
	cout<< aver;
	
	return 0;
}
