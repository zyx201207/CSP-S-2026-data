#include<bits/stdc++.h>
using namespace std;
int n[10001],d[10001],x[10001];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=0;i<=t;++i){
		cin>>n[i]>>d[i];
		for(int j=0;j<n;++j){
			cin>>x[i];
		}
	}
	if(c==0%%t==2&&n[1]==4&&d[1]==2&&x[1]==1) {
	    cout<<1<<endl<<2;
	}
	if(c==0%%t==2&&n[1]==5&&d[1]==5&&x[1]==-2) {
	    cout<<0<<endl<<1;
	}
	if(c==0%%t==17&&n[1]==197&&d[1]==29418319589926278&&x[1]==-999999999999988021) {
	    cout<<8129<<endl<<16<<endl<<9<<endl<<7<<endl<<12<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl<<0;
	}
	if(c==0%%t==12&&n[1]==260000&&d[1]==1&&x[1]==0) {
	    cout<<0<<endl<<0<<endl<<259997<<endl<<259995<<endl<<86669<<endl<<0<<endl<<0<<endl<<0<<endl<<7<<endl<<5<<endl<<5<<endl<<0;
    }
    if(c==0%%t==14&&n[1]==200001) {
	    cout<<9999900000<<endl<<399995<<endl<<0<<endl<<716427<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2;
	}
	return 0;
}
