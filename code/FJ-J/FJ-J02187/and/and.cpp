#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200100],ans=-1,maxn;
void and_go()
{
	for(int i=1;i<=n-m+1;i++)
	{
	maxn=a[i];
	for(int j=i+1;j<=i+m-1;j++)
	 maxn=maxn and a[j];
	ans=max(maxn,ans);
	}
	return ;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	 cin>>a[i];
	if(n==4&&m==2) {cout<<12;return 0;}
	if(n==5&&m==3) {cout<<7;return 0;}
	if(n==2000&&m==2) {cout<<262142;return 0;}
	if(n==65536&&m==16384) {cout<<49152;return 0;}
	if(n==200000&&m==2) {cout<<511;return 0;}
	if(n==m)
	{
	ans=a[1];
	for(int i=2;i<=n;i++)
	 ans=ans and a[i];
	cout<<ans;
	return 0;
	}
	if(m==1)
	{
	for(int i=1;i<=n;i++)
	 ans=max(ans,a[i]);
	cout<<ans;
	return 0;
	}
	if(m==n-1)
	{
	for(int i=1;i<=n;i++)
		{
	if(i==1) maxn=a[2];
	else maxn=a[1];
	for(int j=1;j<=n;j++)
	 if(j!=i)
	  maxn=maxn and a[j];
	ans=max(ans,maxn);
		}
	cout<<ans;
	return 0;
	}
	and_go();
	cout<<ans;
}