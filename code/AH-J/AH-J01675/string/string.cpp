#include<bits/stdc++.h>
using namespace std;
int n,arr[200010];
char ch[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i]>>ch[i];
	}
	long long ans=0;
	for(int i=1,j=n;i!=j;)
	{
		if(ch[i]!=ch[j])
		{
			ans+=min(arr[i],arr[j]);
		}
		if(arr[i]<arr[j])
		{
			arr[j]-=arr[i];
			i++;
		}
		else
		{
			arr[i]-=arr[j];
			j--;
		}
	}
	cout<<ans;
	return 0;
} 
