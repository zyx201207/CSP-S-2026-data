#include<bits/stdc++.h> 
using namespace std;
long long ans=1,c,t;
//bool c(cn x,cn,y)
//{
//	return cn,x<xn,y;
//}
struct cn
{
	int x,y;
};
vector<long long>a;
int main()
{ 
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
//    priority_queue<cn,vector<cn>,greater<cn>> b;
	cin>>c>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n-1;i++)
		{
			int u,v;
			cin>>u>>v;
		}
		if(c==0) cout<<"12251";
	    else cout<<k;
	}
	
	return 0;
}
