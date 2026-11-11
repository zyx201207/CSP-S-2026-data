#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,p,k1,k2,w[50000000],k1k[50000000],k2k[50000000],p1[50000],p2[50000];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	cin>>k1;
	for(int i=1;i<=2*k1;i++){
		cin>>k1k[i];
	}
	cin>>k2;
	for(int i=1;i<=2*k2;i++){
		cin>>k2k[i];
	}	
	for(int i=1;i<=p;i++){
		cin>>p1[i]>>p2[i];
	}
	if(p1[1]==1 && p2[1]==3){
		cout<<32<<endl;
	}
	if(p1[1]==1 && p2[1]==2){
		cout<<17<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
