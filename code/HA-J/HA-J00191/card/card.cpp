#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
const int M=3e5+10;
int a[N];
int ans[M];
int last[M];
int now[N];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int cnt=0;
		for(int j=1;j<=m;j++) last[j]=-1;
		for(int j=i;j<=n;j++)
		{
			cnt++;
			int pos=last[a[j]];
			now[cnt]=a[j];
			if(pos==-1)
			{
				last[a[j]]=cnt;
				continue;
			}
			for(int k=pos+1;k<cnt;k++) last[now[k]]=-1,now[k]=0;
			cnt=pos;
		}
		for(int j=1;j<=m;j++)
		{
			if(last[j]!=-1) ans[j]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
