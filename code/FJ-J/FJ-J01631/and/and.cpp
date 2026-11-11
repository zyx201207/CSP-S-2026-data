#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,o=0,sum=0;
	cin>>n>>m;
	long long a[n],cnt;
	bool e[m][25];
	long long ee[10];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=n-1;i>=n-m;i--)
	{
		cnt=0;
		while(a[i]>0)
		{
			e[o][cnt]=a[i]%2;
			cnt++;
			a[i]/=2;
		}
		o++;
	}
	for(int i=0;i<10;i++)
	{
		ee[i]=1;
		for(int j=0;j<m;j++)
		{
			ee[i]=(ee[i] and e[j][i]);
		}	
	}	
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<i;j++)
		{
			ee[i]*=2;
		}	
	}	
	for(int i=0;i<10;i++)
	{	
		sum+=ee[i];	
	}
	cout<<sum<<endl;
 }

