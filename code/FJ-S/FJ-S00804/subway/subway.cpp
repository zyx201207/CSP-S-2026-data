#include<bits/stdc++.h> 
using namespace std;
long long ans=1,c,n,m,d,q;
vector<long long>a;
//bool c(cn x,cn,y)
//{
//	return cn,x<xn,y;
//}
struct cn
{
	int x,y;
};

int main()
{ 
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//    priority_queue<cn,vector<cn>,greater<cn>> b;
	cin>>c>>n>>m>>d>>q;
	long long zs=0;
	 for(int i=0;i<m;i++)
	 {
	 	int x;
	 	cin>>ans;
	 }
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int x,y;
			cin>>x>>y;
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		cout<<ans;
	}
	return 0;
}
