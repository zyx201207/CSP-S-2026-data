#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int maxi=-1; 
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>maxi) maxi=a[i];
	}
	int and_he=a[1];
	for(int i=2;i<=n;i++)
	{
		and_he=(and_he & a[i]);	
	}
	if(m==1)
	{
		cout<<maxi;
		return 0;
	}
	if(m==n)
	{
		cout<<and_he;
		return 0;
	}
	int maxak=-1;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			int cnt=(a[i]&a[j]);	
			if(cnt>maxak) maxak=cnt;	
		}		
	}
	cout<<maxak;
	return 0;	
} 
