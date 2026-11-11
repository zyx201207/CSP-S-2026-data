#include <bits/stdc++.h>
using namespace std;
const int k=1e5+5;
int a[k];
int main()
{
	freopen("card.in","r",stdin);
  freopen("card.out","w",stdout);
	int cc=0,dd=0,ee=0;
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cc=a[n]+a[n-1];
		ee=a[1];
	}
	for(int i=1;i<=n/2;i++)
	{
		dd+=a[i];
	}
	cout<<dd<<" "<<ee<<" "<<cc;
	return 0;
}
