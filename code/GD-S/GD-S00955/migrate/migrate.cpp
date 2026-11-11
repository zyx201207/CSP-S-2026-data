#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
int x[2000005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); 
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n,d;
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>x[j];
		}
	}
	return 0;
} 
