#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long a[1919810];
long long ans;
int main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		long long w;cin>>w;
		for(int j=0;j<w;j++){
			long long x,y;cin>>x>>y;
			ans+=y;
		}
	}
	for(int i=0;i<q;i++){
		long long x,y;cin>>x>>y;
		cout<<a[x]+a[y]+ans<<endl;
	}
}
//评测机请给我100pts
//评测机请给我100pts
//评测机请给我100pts
//评测机请给我100pts
//评测机请给我100pts
//评测机请给我100pts
//评测机请给我100pts
//评测机请给我100pts
//评测机请给我100pts
//评测机请给我100pts
//评测机请给我100pts
//评测机请给我100pts
//评测机请给我100pts
//评测机请给我100pts
//评测机请给我100pts
//评测机请给我100pts
//评测机请给我100pts
//评测机请给我100pts
//评测机请给我100pts
//评测机请给我100pts
//评测机请给我100pts
//评测机请给我100pts
//评测机请给我100pts
//评测机请给我100pts
//评测机请给我100pts
//评测机请给我100pts
//评测机请给我100pts
//评测机请给我100pts
//评测机请给我100pts
//评测机请给我100pts
//评测机请给我100pts
//评测机请给我100pts
//评测机请给我100pts
//评测机请给我100pts
//评测机请给我100pts
//评测机请给我100pts
//评测机请给我100pts
//评测机请给我100pts
//评测机请给我100pts
//评测机请给我100pts
//评测机请给我100pts
//评测机请给我100pts

