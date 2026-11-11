#include<bits/stdc++.h>
using namespace std;
long long w[1919810],k[1919810],a[1145][1145],t[1145][1145];
int main(){
	long long c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++){
		cin>>w[i];
	}
	for(long long i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--){
		long long x,y;
		cin>>x>>y;
		long long ans=w[x]+w[y];
		for(int i=x;i<=y-1;i++){
			ans+=t[i][i]+t[i][i+1];
		} 
		cout<<ans<<endl;
	}
	return 0;
} 
