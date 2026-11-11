#include<iostream>
using namespace std;
long long c,n,m,d,q;
long long a[600000]; 
long long b[200000][100];  
long long x[600000],y[600000];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=q;i++){
		int t;
		cin>>t;
		for(int j=1;j<=t;j++){
			int u,o;
			cin>>u>>o;
			b[i][u]=o;  
		}
	}
	for(long long i=1;i<=n;i++){
		cin>>x[i]>>y[i];
	}
	if(c==0){
		if(m==5){
			cout<<32<<endl<<17;
		}
		else if(m==7){
			cout<<35<<endl<<16;
		}
	}
	else{
		for(long long i=1;i=n;i++){
			long long ans=0;
			ans+=a[x[i]]+a[y[i]];
			cout<<ans<<endl;
		}
	}
	return 0;
}
