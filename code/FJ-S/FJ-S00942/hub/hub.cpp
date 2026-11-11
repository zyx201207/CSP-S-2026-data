#include<bits/stdc++.h>
using namespace std;
long long u[1000005],v[1000005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	long long c,t;
	cin>>c>>t;
	for(long long l=1;l<=t;l++){
		long long n,k;
		cin>>n>>k;
		for(long long i=1;i<n;i++){
			cin>>u[i]>>v[i];
		}
		cout<<k-u[1]<<"\n";
	}
	
	return 0;
}
