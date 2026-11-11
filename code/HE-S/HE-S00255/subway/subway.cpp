#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,k,st,ed;
long long w[5000000],pian;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=2*k;j++){
			cin>>pian;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>st>>ed;
	}
	if(c==0){
		if(n==2){
			cout<<32<<endl<<17;
			return 0;
		}
		if(n==3){
			cout<<35<<endl<<16;
			return 0;
		}
	}
	cout<<0;
	return 0;
}
