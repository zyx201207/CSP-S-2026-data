#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+9,M=3e5+9;
ll n,m,a[N],h[M];
vector<int>g[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		g[a[i]].push_back(i);
	}
	for(int i=1;i<=m;i++)sort(g[i].begin(),g[i].end());
	for(int i=0;i<=n;i++){
		int p=n,q=i;
		for(int j=1;j<=m;j++){
			int k=upper_bound(g[j].begin(),g[j].end(),i)-g[j].begin();
			if(g[j].size()-k>1){
				q=max(q,g[j][g[j].size()-1]-1);
				p=min(p,g[j][k]);
			}
		}
		for(int j=1;j<=m;j++){
			int k=upper_bound(g[j].begin(),g[j].end(),i)-g[j].begin();
			int k1=upper_bound(g[j].begin(),g[j].end(),p)-g[j].begin();
			int k2=upper_bound(g[j].begin(),g[j].end(),q)-g[j].begin();
			if(k!=k1||k2<g[j].size())h[j]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<h[i]<<" ";
	return 0;
}
