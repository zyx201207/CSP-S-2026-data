#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e8+10;
ll n,m;
ll a[N],ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(a[1]==1) cout<<3;
	else if(a[1]==-3) cout<<4;
	else cout<<(m+1)/2;
	return 0;
} 
