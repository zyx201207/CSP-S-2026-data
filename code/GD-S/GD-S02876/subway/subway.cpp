#include<bits/stdc++.h>
using namespace std;
long long c,m,n,d,q,w[100000],a[500][100000],t[500][100000];
vector<long long> l[501];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>m>>n>>d>>q;
	for(int i=1;i<=m;i++)	cin>>a[i];
	for(int i=1;i<=n;i++){
		long long k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
			if(j>=1){
				l[a[i][j]]=l[a[i][j-1]]=1;
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		dfs(x,y);
	}
	return 0;
} 
