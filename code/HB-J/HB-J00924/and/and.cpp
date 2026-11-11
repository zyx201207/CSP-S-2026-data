#include<bits/stdc++.h>
using namespace std;

int n,m,t1=0;
int a[200010],b[200010],num[200010][35],len[200010];
char s[200010][35];

int main()
{
	freopen("and.in","r",stdin);
	//freopen("and1.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int t=0;b[i]>0;t++)
		{
			b[i]/=2;
			num[i][t]=b[i]%2;
			t1++;
		}
		for(int j=0;j<t1;j++)
		{
			s[i][t1-1-j]=num[i][j];
		}
	}
	int max1=0;
	for(int i=0;i<n;i++)
	{
		len[i]=strlen(s[i]);
		max1=max(max1,len[i]);
	}
	
}
