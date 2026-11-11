#include <bits/stdc++.h>
using namespace std;
int n,m;
int ac[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%d",&ac[i]);
	for(int i=1;i<=m;i++) printf("%d ",i);
	return 0;
}
