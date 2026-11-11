#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],ans,b[N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=29;i>=0;i--)
	{
		int cnt=0;
		for(int j=1;j<=n;j++)
			if(a[j]&(1<<i))
				b[++cnt]=a[j];
		if(cnt>=m)
		{
			n=cnt;
			ans|=1<<i;
			for(int j=1;j<=n;j++)
				a[j]=b[j];
		}
	}
	cout<<ans;
	return 0;
}
