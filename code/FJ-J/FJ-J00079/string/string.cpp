#include<bits/stdc++.h>
using namespace std;
int n,a[200010];
long long ans;
char c[200010];
int read()
{
	int ans=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') ans=ans*10+c-'0',c=getchar();
	return ans;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) 
	{
		a[i]=read();
		cin>>c[i];
	}
	int l=1,r=n;
	while(l<r)
	{
		if(c[l]!=c[r]) ans+=(long long)(min(a[l],a[r]));
		if(a[l]>a[r]) 
		{
			a[l]-=a[r];
			r--;
		}
		else if(a[l]<a[r])
		{
			a[r]-=a[l];
			l++;
		}
		else 
		{
			r--;
			l++;
		}
	}
	cout<<ans;
	return 0;
}
