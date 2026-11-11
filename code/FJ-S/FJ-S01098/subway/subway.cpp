#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005],k[500005],a[1005][1005],t[1005][1005];
vector<int> g[500005];

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			for(int kk=1;kk<=k[i];kk++){
				if(j==kk)	continue;
				g[j].push_back(kk);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=INT_MAX;
		int sum=0;
		for(auto i:g[x]){
			
		}
	}
}

