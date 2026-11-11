#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int c,t;
int u[N],v[N]; 
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n,k; 
		cin>>n>>k;
		for(int j=1;j<n;j++){
			cin>>u[i]>>v[i];
		}
	}
	return 0;
} 
