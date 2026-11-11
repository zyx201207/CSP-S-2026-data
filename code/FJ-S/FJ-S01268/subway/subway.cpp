#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int w[m];
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int k[n],a[n][500000],t[n][500000];
	for(int i=0;i<n;i++){
		cin>>k[i];
		for(int j=0;j<k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	int min[q];
	
	for(int i=0;i<q;i++){
		int x,y;
		cin>>x>>y;
		min[i]=w[x]+w[y];
	}
	for(int i=0;i<q;i++){
		cout<<min[i]<<endl;
	}
	return 0;
}
//1 2   4
//  2 3 4 5

//1 2     5
//  2 3       7
//    3   5_6
//      4
