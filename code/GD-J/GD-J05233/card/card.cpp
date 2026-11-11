#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N=3e5+5,M=5e3+5,mod=1e9+7,INF=1e18;
int n,m,a[N],w[N];
bool bj[N];
deque<int>q;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		memset(bj,0,sizeof(bj));
		while(!q.empty()) q.pop_back();
		for(int j=i;j<=n;j++)
		{
			if(bj[a[j]]) while(q.back()!=a[j]) bj[q.back()]=0,q.pop_back();
			else q.push_back(a[j]),bj[a[j]]=1;
		}
		while(!q.empty()) w[q.back()]++,q.pop_back(); 
	}
	for(int i=1;i<=m;i++)
		cout<<w[i]<<" ";
	return 0;
}
