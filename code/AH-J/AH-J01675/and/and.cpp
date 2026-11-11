#include<bits/stdc++.h>
using namespace std;
int n,m;
pair<string,int> arr[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i].second;
		int t=arr[i].second;
		arr[i].first="";
		while(t>0)
		{
			arr[i].first+=char(t%2+'0');
			t/=2;
		}
		for(int i=1;i<=30-arr[i].first.size();i++)
		{
			arr[i].first+='0';
		}
		reverse(arr[i].first.begin(),arr[i].first.end());
	}
	sort(arr+1,arr+1+m,greater<pair<string,int>>());
	for(int i=m+1;i<=n;i++)
	{
		for(int j=m;j>=1;j--)
		{
			if(arr[j].first>arr[i].first)
			{
				arr[j+1].first=arr[i].first;
				arr[j+1].second=arr[i].second;
				break;
			}
			arr[j].first=arr[j-1].first;
			arr[j].second=arr[j-1].second;
		}
	}
	int sum=arr[1].second;
	for(int i=2;i<=m;i++)
	{
		sum&=arr[i].second;
	}
	cout<<sum;
	return 0;
} 
