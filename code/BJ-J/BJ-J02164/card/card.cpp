#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500010;
int n,m,a[N],tot[N];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		tot[a[i]]++;
	}
	int tmp=n;
	for(int i=1;i<=m;i++)
	{
		cout<<tmp<<" ";
		tmp-=tot[i];
	}
	return 0;
}
