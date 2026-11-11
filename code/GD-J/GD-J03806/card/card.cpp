#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=6e5;
int a[N];
int out[N];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)out[a[i]]+=i;
	for(int i=1;i<=m;i++)cout<<out[i]<<' '; 
}
