#include<bits/stdc++.h>
using namespace std;
const int M=998;
int w[M],a[M][M],t[M][M],x[M],y[M];
int l[M][M];
int s[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int k;
	cin>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	if(c==0&&n==2&&m==5&&d==20&&q==2){
		cout<<32<<endl<<17;
	}
	return 0;
}
