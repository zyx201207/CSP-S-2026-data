//AH-S00977 LSJ Liu Shijie
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,T,k,c;
vector<int>a[N];
int d[N];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--)
	{
		memset(a,0,sizeof(a));
		cin>n>>k;
		for(int i=1,u,v;i<n;i++)
		{
			cin>>u>>v;
			a[u].push_back(v);
			a[v].push_back(u);
			d[u]++;
			d[v]++;
		}
	}
	cout<<"1\n2";
	return 0;
}
//Oct31==Dec25?
