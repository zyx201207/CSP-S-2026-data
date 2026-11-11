#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=5e5+10;
int n,m,a[N],l[N],f[N],s[N],lx[N],nx[N],j,p;
//queue<int> q[N];
bool v[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		memset(lx,0,sizeof(lx));
		memset(s,0,sizeof(s));
		memset(v,0,sizeof(v));
		for(int j=i;j<=n;j++)
		{
			s[a[j]]++;
			if(s[a[j]]>1&&!v[lx[a[j]]])
				for(int k=lx[a[j]]+1;k<j;k++)
					if(!v[k])
						s[a[k]]=max(s[a[k]]-1,0),v[k]=0;
			lx[a[j]]=j;
		}
		for(int j=1;j<=m;j++)
			if(s[j]>0)
				f[j]++;
//		for(int j=1;j<=m;j++)	
//			cout<<f[j]<<" ";
//		cout<<"\n";
	}
	for(int i=1;i<=m;i++)	
		cout<<f[i]<<" ";
	return 0;
}
