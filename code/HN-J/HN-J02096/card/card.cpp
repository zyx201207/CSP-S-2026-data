#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],b[100005],m;
int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		b[a[i]]=i;
	}
	for(int i=1;i<=m;i++) cout<<b[i]<<' '; 
	return 0;
}
