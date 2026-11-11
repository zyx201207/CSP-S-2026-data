#include<bits/stdc++.h>
using namespace std;
int x[200005]={},l[2005][2005][3]={};
int main()
{
	int c,tt;
	cin>>c>>tt;
	for(int h=0;h<tt;h++)
	{
		int n,d;
		cin>>n>>d;
		for(int i=0;i<n;i++)
		{
			int a;
			cin>>a;
			x[i]=a;
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(abs(x[i]-x[j])<=d)
				{
					l[i][j][0]=1;
				}
				else
				{
					l[i][j][1]=0x3f3f3f3f;
				}
			}
		}
	}
	return 0;
}
