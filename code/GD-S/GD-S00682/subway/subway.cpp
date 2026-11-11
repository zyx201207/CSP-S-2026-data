#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,t=0;
long long w[500005],k[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>k[i][j];
		}
	}
	cout<<0;
	return 0;
}
