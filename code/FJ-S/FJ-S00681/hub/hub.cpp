#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	long long c,t;
	cin>>c>>t;
	while(t--){
		long long n,k;
		cin>>n>>k;
		for(long long i=0;i<n;i++){
			long long a,b;
			cin>>a>>b;
		}
		if(k==n)cout<<0;
		int m=(n+1)/2;
		if(m%2==k%2)cout<<max(1ll,(m/2-k/2+1)/2)<<'\n';
		else cout<<max(1ll,(((m+1)/2-k/2+1)/2))<<'\n';
	}
	return 0;
}
