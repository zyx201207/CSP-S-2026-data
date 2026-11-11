#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int  M=1e8+5;
int a[N];
int c[M];
int b[N];
long long ans=0;
int maxn=0,maxn1=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
		
	}
	for(int i=1;i<=m;i++)
	{
		c[i]=i;
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			
			a[b[i]+c[j]]++;
			
		}
	}
	for(int i=0;i<N;i++)
	{
		maxn=max(maxn,a[i]);
		
	}
//	cout<<maxn<<endl;
	
//	for(int i=1;i<=maxn;i++)
//	{
//		cout<<b[i]<<" ";
//		m=m-(maxn-b[i]);
//		ans++;
//
//	}
//	cout<<endl;
	
	maxn1=b[maxn-1];
//	cout<<maxn<<endl;
	for(int i=maxn-1;m>0;i--)
	{
		m=m-(maxn1-b[i]);
//		cout<<b[i]<<" "<<m<<endl;;
		
		ans++;
	}
	cout<<ans;
	return 0;
 } 
