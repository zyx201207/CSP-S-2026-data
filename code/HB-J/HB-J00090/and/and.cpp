#include<bits/stdc++.h>
using namespace std;
int ans=-99999,n,m,num;
int a[200005];
/*void an(int x,int p,int ti)
{
	if(p>=n)
	{
		return;
	}
	if(ti==m-1)
	{
		ans=max(ans,x);
		return;
	}
	int cnt=(x&a[p]);
	
	an(cnt,p+1,ti+1);
}*/
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			int cnt=(a[i]&a[j]);
			ans=max(ans,cnt);
		}
	}
	cout<<ans;
	return 0;
}
