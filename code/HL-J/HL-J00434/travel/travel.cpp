#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
	}else{
		cout<<0;
	}
	int x=(b[1]-'0')*10+(b[2]-'0');
	int y=(d[1]-'0')*10+(d[2]-'0');
	if(x==y){
		if(((b[3]<='A'&&b[3]<='C')&&(d[3]<='A'&&d[3]<='C'))||((b[3]<='D'&&b[3]<='E')&&(d[3]<='D'&&d[3]<='E'))){
			cout<<11;
		}else{
			cout<<10;
		}
	}else{
		if(((b[3]<='A'&&b[3]<='C')&&(d[3]<='A'&&d[3]<='C'))||((b[3]<='D'&&b[3]<='E')&&(d[3]<='D'&&d[3]<='E'))){
			cout<<01;
		}else{
			cout<<00;
		}
	}
	if((b[3]<='A'&&b[3]<='C')&&(d[3]<='A'&&d[3]<='C')&&((b[3]==d[3]+1)||(b[3]==d[3]-1))){
		cout<<1;
	}else if(((b[3]<='D'&&b[3]<='E')&&(d[3]<='D'&&d[3]<='E'))&&((b[3]==d[3]+1)||(b[3]==d[3]-1))){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
