#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans=0;
int a[200005];
void aba(int c,int d,int e)
{
	if(d==1)
	
	{
		if(c>ans) ans=c;
		return;
	}
	for(int i=e+1;i<=n-d+2;i++) aba(c&a[i],d-1,i);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i]; 
	if(m==1) cout<<*max_element(a+1,a+n+1)<<endl;
	else if(m==n)
	{
		int f=a[1];
		for(int i=2;i<=n;i++) f&=a[i];
		cout<<f<<endl;
	}
	else if(m==2)
	{
		for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;j++)
				if(a[i]&a[j]>ans) ans=a[i]&a[j];
		cout<<ans<<endl;
	}
	else
	{
		for(int i=1;i<=n-m+1;i++) aba(a[i],m,i);
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
