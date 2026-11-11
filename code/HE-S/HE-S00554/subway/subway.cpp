#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,n,m,d,q;cin>>c>>n>>m>>d>>q;
	int w[m+1];//从站台到站口的时间 
	for(int i=1;i<=m;i++) cin>>w[i];
	int k1;cin>>k1;int a1[k1+1],t1[k1+1];
	for(int i=1;i<=k1;i++) cin>>a1[i]>>t1[i];
	int k2;cin>>k2;int a2[k2+1],t2[k2+1];
	for(int i=1;i<=k2;i++) cin>>a2[i]>>t2[i];
	
	while(q--)
	{
		int x,y;cin>>x>>y;long long cnt=w[x]+w[y];//cout<<cnt<<endl;
//		long long aaa=0;
		for(int i=1;i<y;i++) 
		{
			cnt+=t1[i];//cout<<cnt<<endl;
			cnt+=t2[i];//cout<<cnt<<endl;
		}
//		cout<<aaa<<endl;
		cout<<cnt<<'\n';
	}
	
	return 0;
}
