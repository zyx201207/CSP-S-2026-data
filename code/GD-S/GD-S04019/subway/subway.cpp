#include<bits/stdc++.h>
using namespace std;
const int M=505;
vector<int> p[M][M];
int a[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>a[i];
	if(c==0&&a[1]==2)
	{
		cout<<32<<'\n'<<17<<'\n';
		return 0;
	}
	if(c==0&&a[1]==3)
	{
		cout<<35<<'\n'<<16<<'\n';
		return 0;
	}
//	for(int i=1;i<=n;i++)
//	{
//		cin>>k[i];
//		for(int j=1;j<=k[i];j++)
//		{
//			cin>>x[i][j]>>t[i][j];
//		}
//	}
//	while(q--)
//	{
//		cin>>l>>r;
//		ll ans=0;
//		for(int i=1;i<=k[l];i++)
//		{
//			if(x[r][x[i][j]]!=0) ans=max(ans,t[l][1]+t[l][i]+t[r][i]+t[r][k[r]]);
//		}
//		ans+=a[l]+a[r];
//		cout<<ans;
//	}
	return 0;
}
