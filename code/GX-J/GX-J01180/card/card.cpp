#include<bits/stdc++.h>
using namespace std;

int n,m,a;
struct card{
	int c;
	int i;
}x[100005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++)
	{
		cin>>a;
		x[a].c++;
		x[a].i=i;
	}
	for(int i=1; i<=m; i++)
	{
		if(x[i-1].c>1) cout<<x[i].c<<" ";
		else cout<<x[i].i<<" ";
	}
	return 0;
}
