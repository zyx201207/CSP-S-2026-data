#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005];
long long k[500005],a[505][505],t[505][505];
long long x[100005],y[100005];
long long sum;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=2*k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<q;i++){
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=q;i++){
		sum=0;
		for(int j=x[i];j<=y[i];j++){
			sum+=w[x[i]]+w[y[i]];
			for(int k=x[i];k<=y[i];k++){
				sum+=t[j][k];
			}
		}
		cout<<sum<<endl;
	}
	return 0;
} 
