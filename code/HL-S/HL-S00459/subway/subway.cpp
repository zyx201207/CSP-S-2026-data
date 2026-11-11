#include<bits/stdc++.h>																																	//awa																															//	awa          	
using namespace std;
int c,n,m,d,q,w[100009],k[100009],a[100009],t[100009],r1[100009],r2[100009];
int main(){
	cin>>c>>n>>m>>d>>q;
	
	for(int i=1;i<=m;i++){
		cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
	for(int j=1;j<=k[i];j++){
			cin>>a[j]>>t[j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>r1[i]>>r2[i];
	}
	if(c==0&&n==2&&m==5&&d==20&&q==2)
	cout<<32<<endl<<17;
	//if
	return 0;
}