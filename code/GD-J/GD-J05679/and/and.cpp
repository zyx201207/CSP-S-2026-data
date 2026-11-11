#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int a,m,b[N];
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>a>>m;
	for(int i=0;i<a;i++)
	{
		cin>>b[i];
	}
	int x=0;
	for(int i=0;i<a;i++)
	for(int j=i+1;j<a;j++)
	x=max(x,b[i]&b[j]);
	cout<<x;
	return 0;
}
