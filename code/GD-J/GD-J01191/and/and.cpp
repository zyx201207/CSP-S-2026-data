#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,k,ans;
long long a[N],pa[N];
bool vis[N];
void s(int x)
{
	if(x>k)
	{
		long long z=pa[1];
		for(int i=2;i<=k;i++)z=z&pa[i];
		ans=max(z,ans);
		return;
	}
	for(int i=x;i<=n;i++)
	{
		if(!vis[i])
		{
			pa[x]=a[i];
			//cout<<pa[x];
			vis[i]=1;
			s(x++);
			vis[i]=0;
		}
		
	}
}

int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	s(1);
	cout<<ans;
	
	return 0;
 } 
