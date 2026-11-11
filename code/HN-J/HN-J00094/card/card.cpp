#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int tot=0;
int a[200005];
int t[200005],ans[200005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,k=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	while(k<=n){
		tot=0;
		memset(t,0,sizeof t);
		vector<int> g;
	    g.push_back(0);
		for(int i=k;i<=n;i++){
			g.push_back(a[i]);
			tot++;
			if(t[a[i]]!=0){
				int x=tot-1,y=g[tot];
				while(g[x]!=y){
					t[g[tot]]--;
					g.pop_back();
					x--,tot--;
				}
				t[g[tot]]--,tot--;
				g.pop_back();
			}
			t[a[i]]++;
		}
		k++;
		for(int i=1;i<=m;i++)if(t[i]!=0)ans[i]++;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
} 
