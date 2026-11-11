#include<bits/stdc++.h>
using namespace std;
long long int n,m;
long long int arr[200005]={};
long long int ans=0;
int fun(int a,int m1)
{
	if(m1==m-1)
	{
		return arr[a+m1];
		cout<<0;
	}
	return fun(a,m1+1)&arr[a];
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	sort(arr+0,arr+n);
	for(int i=1;i<=n;i++)
	{
		long long int c=fun(i,0);
		ans=max(ans,c);
	}
	cout<<ans;
	return 0;
}
