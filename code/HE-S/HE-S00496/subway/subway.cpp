#include<bits/stdc++.h>
using namespace std;
int const N=1e9,M=1e5;
int w[N],a[505][M],r[M][4],cnt[505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++){
		cin>>w[i];
	}
	int z;
	for(int i=1; i<=n; i++){
		cin>>z;
		for(int j=1; j<=z; j++){
			int f,e;
			cin>>f>>e;
			a[i][f]=e;
		} 
	}
	for(int i=1; i<=q; i++){
		cin>>r[i][1]>>r[i][2];
	}
	int sum=0;
	for(int i=1; i<=q; i++){
		sum+=w[r[i][1]]+w[r[i][2]];
		r[i][3]=sum;
	}
	for(int i=1; i<=q; i++){
		cout<<r[i][3]<<" ";
	} 
	return 0;
}
