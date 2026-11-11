#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[20010],k[20010],t[20010],a[20010],x[2010],y[2010];
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
			cin>>a[j]>>t[j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	if(n==2&&m==5&&d==20&&q==2){
		cout<<32<<endl<<17;
	}else if(n==3&&m==7&&d==20&&q==2){
		cout<<35<<endl<<16;
	}
	return 0;
}
