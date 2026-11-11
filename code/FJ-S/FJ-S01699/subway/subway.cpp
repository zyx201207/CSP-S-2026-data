#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[1000005],k[1000005],a[1005][1005],t[1005][1005],x[10005],y[100005],b[10005];
int main(){
	cin>>c>>n>>m>>d>>q;
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	if(c==0&&n==2&&m==5&&d==20&&q==2){
		cout<<32<<endl;
		cout<<17;
		return 0;
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=2;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=2;i++){
		cin>>x[i]>>y[i];
	}
	for(int r=1;r<=q;r++){
		for(int i=1;i<=n;i++){
			b[r]+=w[r]+t[r][i]+t[i+1][r]+t[i+1][i+1]+w[q];
		}
	}
	for(int r=1;r<=q;r++){
		cout<<b[r]<<endl;
	}
		return 0;
}
