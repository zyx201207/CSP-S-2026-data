//GZ-J00608 贵州师范大学附属中学 鲍翰宸 
#include<bits/stdc++.h>
using namespace std;
int js(int r,vector<int> a,int l,int m)
{
	int ans=0;
	if(m>1)
	{
		for (int i=r;i<l;i++)
		{
			ans=max((a[i]&js(i+1,a,l,m-1)),ans);
		}
	}
	else 
	{
		for (int i=r;i<l;i++)
		{
			ans=max(a[i]&INT_MAX,ans);
		}
	}
	return ans;
}
int main()
{
	freopen("and.in","r",stdin) ;
	freopen("and.out","w",stdout) ;
	int m,n,ans=0;
	cin>>n>>m;
	vector<int> a(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		ans=max(ans,js(0,a,i,m));
	}
	cout<<ans;
	return 0;
}
