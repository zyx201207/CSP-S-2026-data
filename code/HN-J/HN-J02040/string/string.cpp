#include<bits/stdc++.h>
using namespace std;
int n,x,y,xx,yy;
long long ans;
int a[200010];
char b[200010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i];
	x=1,y=n,xx=a[x],yy=a[y];
	while(x<=y)
	{
		if(b[x]!=b[y])
			ans+=min(a[x],a[y]);
		xx-=min(a[x],a[y]),yy-=min(a[x],a[y]);
		if(!xx)
			x++,xx=a[x];
		if(!yy)
			y--,yy=a[y];
	}
	cout<<ans;
	return 0;
}
//6
//1000000000 a
//1000000000 a
//1000000000 a
//1000000000 b
//1000000000 b
//1000000000 b
