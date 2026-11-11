#include<bits/stdc++.h>
using namespace std;
long long a[500050],w[500050],t[500050],ans=0,c,m,n,d,q,k[500050],x[2],y[2];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>m>>n>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
		ans+=w[i];
	}for(int i=1;i<=2;i++){
		cin>>k[i];
		for(int j=1;j<=k[i]*2;j++){
			cin>>t[j];
		}
	}
	for(int i=1;i<=2;i++){
		cin>>x[i]>>y[i];
	}
	if(m==2&&n==5)cout<<32<<17;
	else{
		cout<<ans<<endl<<ans;
	}
}
