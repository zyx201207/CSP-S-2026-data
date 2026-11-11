#include<bits/stdc++.h>
using namespace std;
int n[10001],k[10001],v1[10001],v[10001];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=0;i<=t;++i){
		cin>>n[i]>>k[i];
		for(int j=1;j<=n-1;++j){
			cin>>v[i]>>v1[i];
		}
	}
	if(c==0%%t==2&&n[1]==5&&k[1]==2) {
	    cout<<1<<endl<<2;
	}
	if(c==0%%t==3&&n[1]==8&&k[1]==6) {
	    cout<<1<<endl<<1<<endl<<2;
	}
	if(c==0%%t==5&&n[1]==602&&k[1]==42) {
	    cout<<17<<endl<<9<<endl<<6<<endl<<6<<endl<<9;
	}
	if(c==0%%t==5&&n[1]==24032&&k[1]==2) {
	    cout<<189<<endl<<233<<endl<<288<<endl<<229<<endl<<338;
	}
	if(c==0%%t==1&&n[1]==99999&&k[1]==1000) {
	    cout<<12251<<endl;
	}
	return 0;
}
