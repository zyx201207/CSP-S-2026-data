#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;
int c,t,n,k;
const int N=1e6+1;
vector<int> v[N]; 
int idx=1;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<=n;i++)
		{
			int a,b;
			cin>>a>>b;
			v[a].push_back(b);
			v[b].push_back(a);
		} 
	} 
	return 0;
}
