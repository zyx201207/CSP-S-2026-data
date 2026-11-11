#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
int n,m;
int a[N],z[5001][3001],b[M];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i],b[a[i]]=max(i,b[a[i]]);
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;)
		{
			z[i][a[j]]++,j=b[a[j]]+1;
		}
	}
	for(int i=1;i<=m;i++)
	{
		int ans=0;
		for(int j=1;j<=n;j++)
			if(z[j][i]>0) ans++;
		cout<<ans<<' ';
	}
	return 0;
}

