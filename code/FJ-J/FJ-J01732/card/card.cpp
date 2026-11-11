#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int n,m,a[N],b[N],ans[M],c[M];
bool v[M];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int last=0;
		memset(v,0,sizeof(v));
		for(int j=i;j<=n;j++)
		{
			if(!v[a[j]]) b[++last]=a[j],v[a[j]]=1,c[a[j]]=last;
			else
			{
				for(int k=c[a[j]]+1;k<=last;k++) v[b[k]]=0,b[k]=0;
				last=c[a[j]];
			}
		}
		for(int i=1;i<=last;i++) ans[b[i]]++;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
