#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+5;
const ll M=1061109567;
ll a[N];
int ne[N];
int f[N];
int cnt[N];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		ll n,d;
		cin>>n>>d;
		memset(ne,0,sizeof(ne));
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<n;i++)
		{
			ll m=a[i]+d;
			int r=i+1;
			if(a[r]>m)break;
			while(a[r]<=m)
			{
				if(!ne[r])ne[r]=i;
				r++;
			}
		}
		int ans=0;
		for(int k=1;k<n;k++)
		{
			memset(f,0x3f3f3f3f,sizeof(f));
			memset(cnt,0,sizeof(cnt));
			f[k]=1;//f i表示从1到i的最短路长度 
			for(int i=k+1;i<=n;i++)
			{
				for(int j=max(ne[i],k);j<i;j++)
				{
					
					if(ne[i]==0)break;
					f[i]=min(f[i],f[j]+1);
				}
				for(int j=max(ne[i],k);j<i;j++)
				{
					if(ne[i]==0)break;
					if(f[j]+1==f[i])cnt[i]++;
				}
			}
			for(int i=k+1;i<=n;i++)
			{
				ans+=(cnt[i]==2);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5 
RP++
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
