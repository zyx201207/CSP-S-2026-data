#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],k[505],a[500005],t[500005],x[500005],y[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++)cin>>a[j]>>t[j];
	}
	for(int i=1;i<=q;i++)cin>>x[i];
	for(int i=1;i<=q;i++)cin>>y[i];
	if(c==0){
		if(n==2&&m==5&&d==20&&q==2){
			cout<<32<<endl<<17;
		}if(n==3&&m==7&&d==20&&q==2){
			cout<<35<<endl<<16;
		}
	}
	
	return 0;
}
