#include<bits/stdc++.h>
using namespace std;
const int maxn=2*1e5+200;
long long a[maxn]; 
long long n,ans,sum;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ans=max(ans,a[i]);
	}
	cout<<ans;
}
