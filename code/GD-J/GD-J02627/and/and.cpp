#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans;
long long a[200005];
bool b[200005];
void f(int i,long long sum)
{
	if(i==m)
	{
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i]==0)
		{
			b[i]=1;
			f(i+1,sum&a[i]);
			b[i]=0;
		}
	}
}
int main()
{
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	f(0,0);
	cout<<ans;
	return 0; 
} 
