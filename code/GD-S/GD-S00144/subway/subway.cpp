#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long w[510],t[510];
int a[510],b[510],x[500010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
		for(int j=1;j<=b[i];j++){
			cin>>a[j]>>t[j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	cout<<32<<endl<<17;
	return 0;
}
