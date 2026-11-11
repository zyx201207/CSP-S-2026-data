#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	bool f=0,f1=0,f2=0;
	cin>>a>>b>>c>>d;
	if(a[0]==c[0]&&a[1]==c[1]){
		f=1;
		cout<<1;
	}else{
		cout<<0;
	}
	if(f&&b[0]==d[0]&&b[1]==d[1]){
		cout<<1;
		f1=1;
	}else{
		cout<<0;
	}
	if(f1&&b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C'||f1&&b[2]>='D'&&b[2]<='E'&&d[2]>='D'&&d[2]<='E'){
		cout<<1;
		f2=1;
	}else{
		cout<<0;
	}
	if(f2&&max(b[2]-'A',d[2]-'A')-min(b[2]-'A',d[2]-'A')==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
