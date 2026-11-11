#include <bits/stdc++.h>
using namespace std;
long long c,t;
long long n,k;
long long u[1000000],v[1000000];

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>u[i]>>v[i];
		}
	}
	
	return 0;
} 

