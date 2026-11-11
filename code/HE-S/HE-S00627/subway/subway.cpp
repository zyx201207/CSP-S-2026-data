#include<bits/stdc++.h>
using namespace std;
const int M=5e5+10;
int c,n,m,d,q;
long long w[M],b[M],l[M],x[M],y[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		for(int j=1;j<=M;j++){
			cin>>b[j]>>l[j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=q;i++){
		cout<<w[i]+b[i]+l[i]+x[i]+y[i]<<endl;
	}
	return 0;
}
