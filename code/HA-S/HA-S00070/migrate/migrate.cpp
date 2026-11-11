#include <bits/stdc++.h>
using namespace std;
long long c,t,n,d,cnt; 
long long x[3000000];


int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	for(long long i=1;i<=t;i++){
		cin>>n>>d;
		for(long long j=1;j<=n;j++){
			cin>>x[j];
		}
		cout<<n-d*2+1;
	}
	
	return 0;
} 

