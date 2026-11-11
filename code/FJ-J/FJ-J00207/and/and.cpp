#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	long long arr[200001];
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	sort(arr,arr+n);
	int maxn=0;
	for(int i=n-1;i>0;i--)
	{
		int flag=arr[i-1]&arr[i];
		maxn=max(flag,maxn);
	}
	cout<<maxn;
	return 0;
}
