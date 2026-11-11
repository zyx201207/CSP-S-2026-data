#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,a[N];
long long cnt;
char c[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	int x=1,y=n,m;
	while(x<y)
	{
		m=min(a[x],a[y]);
		if(c[x]!=c[y])
		{
			cnt+=m;
		}
		a[x]-=m;
		a[y]-=m;
		if(a[x]==0)x++;
		if(a[y]==0)y--;
	}
	cout<<cnt;
	return 0;
} 
