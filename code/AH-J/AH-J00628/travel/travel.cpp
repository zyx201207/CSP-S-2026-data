#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
	}
	else {
		cout<<"0000";
		return 0;
	}
	if(b[0]+b[1]==d[0]+d[1])cout<<1;
	else {
		cout<<"000";
		return 0;
	}
	if(b[2]>='A'&&b[2]<='C'){
		if(d[2]>='A'&&d[2]<='C'){
			cout<<1;
			if(abs(d[2]-b[2])==1)cout<<1;
			else cout<<0;
		}else{
			cout<<"00";
		}
	}else{
		if(d[2]>='D'&&d[2]<='E')cout<<"11";
		else cout<<"00";
	}
	return 0;
}
