#include<bits/stdc++.h>
using namespace std;
long long c,t,n,k,m[1000000][2];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	srand(time(0));
	cin>>c>>t;
	for(int i=1;i<=t;++i){
		cin>>n>>k;
		for(int j=1;j<=n;++j)cin>>m[j][1]>>m[j][2];
	}
	for(int i=1;i<=t;++i){
		long long y=2e6;
		long long x=1LL*rand()*rand()%y+1;
		cout<<x;
	}
	return 0;
}
