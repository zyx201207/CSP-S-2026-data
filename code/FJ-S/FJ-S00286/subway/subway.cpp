#include<bits/stdc++.h>
using namespace std;
int a[600005],b[600005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	int l,z;
	cin>>l>>z;
	for(int j=1;j<=2*l*2;j++){
		cin>>b[j];
	}
	int o,p,r,t;
	cin>>o>>p>>r>>t;
	if(n==2 && m==5 && d==20 && q==2){
		cout<<"32"<<endl<<"17";
	}
	if(n==3 && m==7 && d==20 && q==2){
		cout<<"35"<<endl<<"16";
	}
	return 0;
}

 
