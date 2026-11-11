#include<bits/stdc++.h>
using namespace std;
const int M=5e5+5;///////
int n,ans=1,a[M];
long long m,k,p,d[M],s[M];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++)d[i]=a[i+1]-a[i];
	sort(d+1,d+n);
	int j=1;
	for(int i=1;i<n;i++)
	{
		if(d[i]!=0)s[j]=d[i]+s[j-1],j++;
	}
	for(int i=1;i<=n;i++)
	{
		if(k+s[i]<=m)
		{
			ans+=1;
			k+=s[i];
		}
		else
		{
			while(a[i]==a[i+1])ans++,i++;
			break;
		} 
	}
	cout<<ans;
//	for(int i=1;i<=n;i++)cout<<s[i]<<'\n';
	return 0;
}
