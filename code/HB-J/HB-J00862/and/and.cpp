#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans,b[5];
int dfs(int c,int mm)
{
	if(c>=n)
	{return -1;}
	if(mm==m){return a[c];}//
	return max(dfs(c+1,mm),dfs(c+1,mm+1)&a[c]);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;++i)
	{
		cin>>a[i];
		if(a[i]<=4)b[a[i]]++;
		if(a[i]==0)
		{
			cout<<"0";//(+)
			return 0;
		}
	}
	if(m==1)//+
	{
		sort(a,a+n);
		cout<<a[n-1];
	}
	else if(m==n)//+
	{
		ans=a[0];
		for(int i=0;i<n;++i)
		{
			ans&=a[i];
		}
		cout<<ans;
	}
	else if(m==2)//3+
	{
		ans=-99999;
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<n;++j)
			{
				if(i==j)continue;
				else ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
	}
	else if(n<=20)//5+
	{
		cout<<dfs(0,0);
	}
	else//2+
	{
		if(b[4]>=m)cout<<4;
		else if(b[3]>=m)cout<<3;
		else if(b[2]+b[3]>=m)cout<<2;
		else cout<<1;
	}
	return 0;
}
//Total:12 or 13
