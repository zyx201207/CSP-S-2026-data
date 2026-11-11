#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("trsvel.in","r",stdin);
	freopen("trsvel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a[0]==c[0]&&a[1]==c[1]) cout<<1;
	else {
		cout<<"0000"<<endl;
		return 0;
	}
	if(b[0]==d[0]&&b[1]==d[1]){
	   cout<<1;
	   if((int)b[2]>=65&&(int)b[2]<=67&&(int)d[2]>=65&&(int)d[2]<=67)cout<<1;
	   else if((int)b[2]>=68&&(int)b[2]<=69&&(int)d[2]>=68&&(int)d[2]<=69)cout<<1;
	   else cout<<0;
	}
	else cout<<0<<0;
	if((b[2]==d[2]&&b[0]==d[0]&&abs((int)b[1]-(int)d[2]))||((b[1]=='9'&&d[1]==0)||(d[1]=='9'&&b[1]==0))){
		cout<<1<<endl;
	}
	else if(b[0]==d[0]&&b[1]==d[1]&&abs((int)(b[2])-(int)(d[2]))==1&&(b[2]!='C'||d[2]!='D')&&(b[2]!='D'||d[2]!='C')){
		cout<<1<<endl;
	}
	else cout<<0<<endl;
	return 0;	
} 
