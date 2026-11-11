#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	vector<long long>arr(n);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	sort(arr.begin(),arr.end(),greater<int>());
	long long ans=1,a=arr[0];
	for(int i=1;i<n;i++)
	{
		if(arr[i]!=a)
		{
			ans=1;
			a=arr[i];
		}
		else
		{
			ans++;
			if(ans==m)
			{
				cout<<arr[i];
				return 0;
			}
		}
	}
	cout<<arr[m-1];
	return 0;
}
