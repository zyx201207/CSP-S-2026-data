#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	bool ok=0,ok1=0,ok2=0;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<"1";
		ok=1;
	}else{
		cout<<0;
	}//1
	if(ok==1&&b[0]==d[0]&&b[1]==d[1]){
		cout<<"1";
		ok1=1;
	}else{
		cout<<0;
	}//2
	if(ok1==1&&ok==1&&'A'<=b[2]&&b[2]<='C'&&'A'<=d[2]&&d[2]<='C'){
		cout<<"1";
		ok2=1;
	}else if(ok1==1&&ok==1&&'D'<=b[2]&&b[2]<='E'&&'D'<=d[2]&&d[2]<='E'){
		cout<<"1";
		ok2=1;
	}else{
		cout<<0;
	}//3
	long long x=int(b[2]);
	long long y=int(d[2]);
	if(x>=y){
		if(ok==1&&ok1==1&&ok2==1&&abs(x-y)==1&&d[2]!='C'){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		if(ok==1&&ok1==1&&ok2==1&&abs(x-y)==1&&b[2]!='C'){
			cout<<1;
		}else{
			cout<<0;
		}
	}//4
	return 0;
}
