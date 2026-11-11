#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int b,n,m,d,q;
	cin>>b>>n>>m>>d>>q;
	int w[m],fr,to;
	for(int i=0;i<m;i++) cin>>w[m];
	for(int i=0;i<n;i++){
		int k;cin>>k;
		for(int j=0;j<k;j++){
			int u,v;cin>>u>>v;
		}
	}
	for(int i=0;i<q;i++) {
		cin>>fr>>to;
		cout<<rand()%n*to*d*q;
	}
	return 0;
}
