#include<bits/stdc++.h>
using namespace std;
int a[1000000],b[10000][10000];
int main(){
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
int c,n,m,d,q,k,z,w;
cin>>c>>n>>m>>d>>q;
for(int i=0;i<m;i++){
	cin>>a[i];
}
for(int i=1;i<=n;i++){
	cin>>k;
	for(int j=0;j<2*k;j++){
		cin>>b[j][i];
	}
}
	for(int i=1;i<=q;i++){
		cin>>z>>w;
	}
	
	return 0;
}
