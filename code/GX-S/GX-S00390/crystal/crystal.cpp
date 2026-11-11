#include<bits/stdc++.h>
using namespace std;
long long int n,m,ans=0;
long long int arr[5005]={0};
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	for(int i=1;i<=n;i++)
	{
		long long int ans1=0,m1=m;
		for(int j=1;j<=n;j++)
		{
				if(m1>=(arr[i]-arr[j]) && arr[j]<=arr[i])
				{
					m=m-(arr[i]-arr[j]);
					ans1++;
				}
		}
		ans=max(ans,ans1);
	}
	cout<<ans;
	return 0;
}
