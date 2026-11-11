#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n,m;
	cin>>n>>m;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	sort(arr,arr+n);
	int brr[(n+1)/2]={};
	for(int i=0;i<(n+1)/2;i++)
	{
		brr[i]=arr[i];
	}
	int t=brr[(n+1)/2-1];
	int s=1;
	for(int i=0;i<(n+1)/2;i++)
	{
		if(brr[i]==t)
		{
			s++;
		}
	}
	for(int i=(n+1)/2-2;i>=0;i--)
	{
		if(m==0)
		{
			break;
		}
		int k=0;
		k=t-brr[i];
		m-=k;
		if(m<0)
		{
			break;
		}
		s++;
	}
	cout<<s;
	return 0;
}
