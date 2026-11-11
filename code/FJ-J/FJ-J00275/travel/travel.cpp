#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	if(b[0]+b[1]==d[0]+d[1]){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	long long cmp1=(b[2]-'A'),cmp2=(d[2]-'A');
	if((cmp1>2&&cmp2>2)||(cmp1<=2&&cmp2<=2)){
		cout<<"1";
	}else{
		cout<<"00";
		return 0;
	}
	if(abs(cmp1-cmp2)==1&&((b[2]!='C'&&d[2]!='D')&&(d[2]!='C'&&b[2]!='D'))){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
}