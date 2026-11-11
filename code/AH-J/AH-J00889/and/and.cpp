#include<bits/stdc++.h>
using namespace std;
int a[200001];
int main() 
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	long long ans=0;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
	  if(a[i]>a[i-1]) swap(a[i],a[i-1]);
	}
	ans=a[0];
	for(int i=1;i<m;i++) 
	{
		ans=ans&a[i];
	}
    cout<<ans;
	return 0;
}
