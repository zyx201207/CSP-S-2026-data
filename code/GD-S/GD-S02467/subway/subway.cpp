#include<bits/stdc++.h>

using namespace std;
int m,n,q,k,d,c,w[500005],a[30][500005],t[30][500005],x,y,cnt=0;
int main(){
	ifstream("subway.in");
	ofstream("subway.out");
	cin>>c;
	cin>>n;
	cin>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cnt=0;
		cin>>x>>y;
		cnt=w[x]+w[y];
	}
} 
