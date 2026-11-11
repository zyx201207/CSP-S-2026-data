#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	int a[n+2];
	for(int i = 0; i < n; i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	long long sum = 0; 
	long long ans = 1;
	for(int i = 0; i < n-1; i++)
	{	
		if((a[i+1]-a[i])*(i+1)+sum>m){
			cout<<ans;
			return 0;
		}
		else
		{
			sum+=(a[i+1]-a[i])*(i+1);
			ans++;
		}
	}
	cout<<ans;
	
	return 0;
}
