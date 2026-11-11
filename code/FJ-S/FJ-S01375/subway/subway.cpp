#include<bits/stdc++.h>
using namespace std;
long long n,m,c,q,d,x,y;
bool f=1;
long long w[505],k[505],a[505],t[505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++){
		cin>>w[i];
	}
	for(long long i=1;i<=n;i++){
		cin>>k[i];
		if(k[i]>2){
			f=0;
		}
		for(long long j=1;j<=k[i];j++){
			cin>>a[i]>>t[i];
		}
	}
	for(long long i=1;i<=q;i++){
		cin>>x>>y;
		if(f==1){
			cout<<w[x]+w[y]+t[x]<<"\n";
		}
		cout<<w[x]+w[y]+t[x]+t[y]<<"\n";
	}
	return 0;
}
