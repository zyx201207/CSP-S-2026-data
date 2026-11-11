#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int ma=-1;
	if(m==1)
	{
		for(int i=0;i<n-1;i++)
		{
			ma=max(ma,a[i]&0);
		}
	}else
	{
		for(int i=0;i<n-1;i++)
		{
			for(int j=i+1;j<n;j++)
				ma=max(ma,a[i]&a[j]);
		}
	}
	cout<<ma;
}
