#include<bits/stdc++.h>
using namespace std;
const int N=520,M=5e5+10;
int w[N],a[M],t[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int i=1;i<=k;i++){
			cin>>a[i]>>t[i];
		}
	}
	while(q--){
		int r1,r2;
		cin>>r1>>r2;
	}
	return 0;
}
