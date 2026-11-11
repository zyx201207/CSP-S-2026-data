#include <bits/stdc++.h>
using namespace std;
int n,a[200005],cnt,ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		char y;
		scanf("%d %c",&x,&y);
		int z=(int)y;
		while(x--)a[++cnt]=z;
	}
	for(int i=1,j=cnt;i*2<=cnt;i++,j--)
		if(a[i]!=a[j])ans++;
	cout<<ans;
	return 0;
}