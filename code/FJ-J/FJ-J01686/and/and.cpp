#include<bits/stdc++.h>
using namespace std;
int n,m,ans,pos[200005],cnt;
long long a[200005];
bool cmp(int a,int b)
{
	return a>b;
} 
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=32;i>=1;i--)
	{
		for(int j=1;j<=n;j++)
			if(a[j]&(1<<i))
			{
				ans++;
				pos[++cnt]=a[j];
			}
			if(ans==m)
				break;
	}
	for(int i=1;i<=m;i++)
	{
		ans&=pos[i];	
	} 
	
	cout<<ans;
	
	
	
	
	return 0;
}
