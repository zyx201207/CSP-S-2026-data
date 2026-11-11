#include <bits/stdc++.h>
using namespace std;
const int N = 200000+5;
int n,m;
int a[N];
int cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n,cmp);
	
	int x=a[m];
	
	int t=0;
	while(x>0)
	{
		t++;
		x/=2;
	}
	int standard=1;
	for(int i=1;i<=t;i++)
		standard*=2;
	
	for(int i=1;i<m;i++)
	{
		while(a[i]>=standard)
			a[i]/=2;
	}
	
	int ans=0;
	for(int i=0;i<t;i++)
	{
		int flag=1;
		for(int j=1;j<=m;j++)
		{
			if(a[j]%2==0)flag=0;
			a[j]/=2;
		}
		if(flag==1)ans+=pow(2,i);
	}
	cout<<ans;
	return 0;
}
