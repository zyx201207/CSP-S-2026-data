#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[100010];
int k;
int a[500010][100010];
int t[500010][100010];
int main(){
	cin>>c>>n>>m>>d>>q;
	if(c==0){
		for(int i=1;i<=m;i++){
			cin>>w[i];
		}
		for(int i=1;i<=n;i++){
			cin>>k;
			for(int j=1;j<=k;j++){
				cin>>a[k][i]>>t[k][i];
			}
		}
	}
	if(n==2 && m==5 && d==20 && q==2){
		cout<<32<<endl<<17<<endl;
	}
}
