#include<bits/stdc++.h>
using namespace std;
int c,t;
long long n,k;
long long u[2000010],v[2000010],s[2000010];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		long long num=0;
		for(int i=1;i<n;i++)
		{
			cin>>u[i]>>v[i];
			if(s[u[i]]==0 && s[v[i]]==0)
			{
				num++;
				s[u[i]]=1;
				s[v[i]]=1;
			}
		}
		cout<<k-1<<endl;
		for(int i=1;i<=n;i++)
		{
			s[u[i]]=0;
			s[v[i]]=0;			
		}
	}
	return 0;
}
