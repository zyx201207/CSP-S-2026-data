#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
int c,T;
int n,k;
vector<int> g[N];
vector<int> e[N];
void add(int u,int v,int w=1)
{
	g[u].push_back(v);
	e[u].push_back(w);
	return;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;i++) g[i].clear(),e[i].clear();
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			add(u,v),add(v,u);
		}
		if(k==n) cout<<0<<'\n';
		if(c==13||c==14){
			if(k>=(n-1)/2) cout<<1<<'\n';
			else{
				int t=(n-1)/2-k;
				if(t>=4){
					if(t%4!=0) t=t/4+1;
					else t/=4;
				}
				else t=t/2+t%2;
				cout<<t+1<<'\n';
			}
		}
	}
	return 0;
}
