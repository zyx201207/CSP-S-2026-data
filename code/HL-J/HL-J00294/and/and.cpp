#include<bits/stdc++.h>
using namespace std;
int n,m,sum=0;

int main() 
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	int a[n];
	long long l[n][n];
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for (int i=0;i<=n;i++)
	{
		for (int j=0;j<=n;j++)
		{
			if (m==2)
			{
				l[i][j]=(a[i]&a[j+1]);				
			}
			if (m==3)
			{
				l[i][j]=(a[i]&a[j+1]&a[j+2]);				
			}
			if (m==4)
			{
				l[i][j]=(a[i]&a[j+1]&a[j+2]&a[j+3]);				
			}
			if (m==5)
			{
				l[i][j]=(a[i]&a[j+1]&a[j+2]&a[j+3]&a[j+4]);				
			}
			if (m==6)
			{
				l[i][j]=(a[i]&a[j+1]&a[j+2]&a[j+3]&a[j+4]&a[j+5]);				
			}
			if (m==7)
			{
				l[i][j]=(a[i]&a[j+1]&a[j+2]&a[j+3]&a[j+4]&a[j+5]&a[j+6]);				
			}
			if (m==8)
			{
				l[i][j]=(a[i]&a[j+1]&a[j+2]&a[j+3]&a[j+4]&a[j+5]&a[j+6]&a[j+7]);				
			}
			if (m==9)
			{
				l[i][j]=(a[i]&a[j+1]&a[j+2]&a[j+3]&a[j+4]&a[j+5]&a[j+6]&a[j+7]&a[j+8]);				
			}
		}
	}
	for (int i=0;i<=n;i++)
	{
		for (int j=0;j<=n;j++)
		{
			sum = max(l[i][j],l[i][j+1]);
			cout <<sum << endl;
		}
	}
	return 0;
}
