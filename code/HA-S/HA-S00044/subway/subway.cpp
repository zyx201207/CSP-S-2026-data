#include<iostream>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q,a[1001]={},b[101][101]={},l=0;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		cin>>l;
		for(int j=1;j<=l*2;j++){
			cin>>b[i][j];
		}
	}
	long long z[q+1]={};
	for(int k=1;k<=q;k++){
		int i,o;
		cin>>i>>o;
		z[k]=a[i]+a[o];
		for(int v=1;v<=l*2;v++){
			if(v!=1&&v%2==1){
				z[k]+=b[1][v];
			}
		}
	}
	for(int i=1;i<=q;i++){
		cout<<z[i]<<endl;
	}
	return 0;
} 
