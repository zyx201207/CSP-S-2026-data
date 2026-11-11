#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;char wod;string a;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>m>>wod;
		for(int j=1;j<=m;j++) a+=wod;
	}
	for(int i=a.size()/2-1;i>=0;i--) if(a[i]!=a[a.size()-i-1]) ans++;
	cout<<ans;
	return 0;
}
