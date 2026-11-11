#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k,waytime[500001],l,r,lx[501][500001],times[501][500001];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>waytime[i];
	}
	cin>>k;
	for(int i=0;i<n;i++){
		for(int j=0;j<k;j++){
			cin>>lx[i][j]>>times[i][j];
		}
	}
	cin>>q;
	while(q--){
		cin>>l>>r;
		cout<<waytime[0]+times[0][1]+times[0][2]+times[1][1]+times[1][2]+waytime[3];
	}
	return 0;
}

