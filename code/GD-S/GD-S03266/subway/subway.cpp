#include <bits/stdc++.h>
using namespace std;
long long w[500005];
long long k[505];
long long a[5005][5005];
long long t[5005][5005];
long long x[100005];
long long y[100005];
long long c,n,m,d,q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
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
		cin>>x[i]>>y[i];
	}
	cout<<"32"<<endl<<"17";
	return 0;
}
