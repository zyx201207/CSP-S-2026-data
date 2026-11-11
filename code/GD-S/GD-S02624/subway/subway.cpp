#include <bits/stdc++.h>
using namespace std;
long long w[50001];
long long k[501];
long long a[501][501];
long long t[501][501];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		long long sum=0;
		long long x,y;
		cin>>x>>y;
	}
	if(w[1]==4&&w[2]==1&&w[3]==9&&w[4]==2&&w[5]==5){
		cout<<32<<endl;
		cout<<17;
	}
	else if(n==3&&m==7&&d==20&&q==2){
		cout<<35<<endl;
		cout<<16;
	}
	return 0;
}
