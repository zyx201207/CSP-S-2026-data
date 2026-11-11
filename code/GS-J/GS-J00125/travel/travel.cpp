#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,c;
	string b,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(a==c&&(b[0]==d[0]&&b[1]==d[1])){
		cout<<"1";
	}else{
		cout<<"0";
	}
	int e=b[2],f=d[2];
	if(a==c&&(b[0]==d[0]&&b[1]==d[1]&&(e+f<=133||e+f>136))){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(b[0]==d[0]&&b[1]==d[1]&&(e==f-1||e==f+1)&&(e+f<=133||e+f>136)){
		cout<<"1";
	}else{
		cout<<"0";
	}
return 0;
}
