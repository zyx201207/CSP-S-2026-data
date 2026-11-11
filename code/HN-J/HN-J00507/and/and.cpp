#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int>v,q;
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int a;
		cin>>a;
		v.push_back(a);
	 } 
	 for(int id=31;id>=0;id--)
	 {
	 	for(auto x:v)
	 	{
	 		if((x&(1<<id)))
	 		{
	 			q.push_back(x);
			 }
		 }
		 if(q.size()>=m)
		 {
		 	ans+=(1<<id);
		 	v.clear();
		 	for(auto x:q)
		 	{
		 		v.push_back(x);
			 }
		 }
		 q.clear();
	 }
	 cout<<ans;
	return 0;
}
//??? 01trie,hyw 
//Ïë¶àÁË 
//T1 16min T2 1h5min T3 9min
//T1+T2 1h21min,butT1+T2+T3 1h30min problem have no order£¿£¿£¿ 
