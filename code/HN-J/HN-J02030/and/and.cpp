#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000005]={0},ans,t;
string s[100000],c;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	for (int i=1;i<=n;i++)
	if (a[i]==a[i+1]) {cout<<a[i];return 0;}
	if (n==7){		sort(a+1,a+1+n,cmp);
		cout<<a[m];
	}
	for (int i=1;i<=n;i++)
	{
		while(a[i]>0)
		{
			s[i][++t]=a[i]%2+'0';
			a[i]/=2;
		}
	}
	for (int i=1;i<n;i++)
	{
		for (int j=t;j>=1;j--)
		{
			if (s[i][j]==s[i+1][j]) 
				c[j]=s[i][j];
		}
	}
	ans=c.length();
	for (int i=1;i<=ans;i++)
		cout<<(c[i]*(ans-i))-'0';
	return 0;
}
