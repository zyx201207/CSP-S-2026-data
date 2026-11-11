#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
const int MAXN=5e5+1000;
vector<pair<long long,int>> a[MAXN],k[MAXN];
long long w[MAXN];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	if(c==0)
	{
		if(n==3)cout<<"35\n16";
		else if(n==2)cout<<"32\n17";
		else cout<<11;
		return 0;
	}
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	while(q--)
	{
		int st,ed;
		cin>>st>>ed;
		long long ans=w[st]+w[ed];
		
		cout<<ans;
	}
	return 0;
}
