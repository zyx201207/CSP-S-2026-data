#include<bits/stdc++.h>
using namespace std;

string b,d;
int s,a,c;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a%17==c%17){
		s=s*10+1;
	}else{
		cout<<"0000"<<endl;
		return 0;
	}
	if(b[0]==d[0] && b[1]==d[1]){
		s=s*10+1;
	}else{
		cout<<"1000"<<endl;
		return 0;
	}
	if((b[2]<'D' && d[2]<'D') || (b[2]>'C' && d[2]>'C')){
		s=s*10+s;
	}else{
		cout<<"1100"<<endl;
		return 0;
	}
	if(int(b[2])-int(d[2])==1 || int(b[2])-int(d[2])==-1){
		s=s*10+1;
	}else{
		cout<<"1110"<<endl;
		return 0;
	}
	cout<<s<<endl;
	return 0;
}
