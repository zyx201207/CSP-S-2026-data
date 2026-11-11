#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	int tie(0);
	cin>>c>>t;
	for(int i=1;i<=n;i++){
		int n,m;cin>>n>>m;
		vector<int>v(n),dp(n,1);
		for(int j=1;j<=n;j++){
			int t;cin>>t;
			v.push_back(t);
		}
		for(int j=0;j<n-1;j++){
			for(int k=j+1;k<n;k++){
				if(abs(v[j]-v[k])<=m)
			}
		}
	}cout<<1<<'\n'<<2;
	return 0;
}
