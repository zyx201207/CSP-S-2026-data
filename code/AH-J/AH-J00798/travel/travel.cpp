#include<bits/stdc++.h>
using namespace std;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	for(int i=0;i<2;i++){
		if(a[i]!=c[i]){
			cout<<"0000";
			return 0;
		}
	}
	cout<<1;
	for(int i=0;i<2;i++){
		if(b[i]!=d[i]){
			cout<<"000";
			return 0;
		}
	}
	cout<<1;
	if((b[2]=='D'&&d[2]!='F')||(d[2]=='D'&&b[2]!='F')||(b[2]=='F'&&d[2]!='D')||(d[2]=='F'&&b[2]!='D')){
		cout<<"00";
		return 0;
	}
	cout<<1;
	int e=d[2]-'A',f=b[2]-'A';
	if(abs(e-f)==1){
		cout<<1;
		return 0;
	}
	cout<<0;
	return 0;
}
