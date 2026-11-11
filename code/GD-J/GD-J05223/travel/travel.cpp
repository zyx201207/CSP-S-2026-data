#include<bits/stdc++.h>
using namespace std;
#define int long long
string n,m,a,b;
int c,d;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m>>a>>b;
	if(n==a){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
		
	}
	for(int i=0;i<3;i++){
		if(m[i]>='0'&&m[i]<='9'){
			c=c*10+m[i]-'0';
		}
		if(b[i]>='0'&&b[i]<='9'){
			d=d*10+b[i]-'0';
		}
	}
	if(c==d){
		cout<<"1";
	}else{
		cout<<"000"; 
		return 0;
	}
	if(m[2]<='C'&&b[2]<='C'||m[2]>'C'&&b[2]>'C'){
		cout<<"1";
	}else{
		cout<<"00";
		return 0;
	}
	if(m[2]-b[2]==1||b[2]-m[2]==1){
		cout<<"1";
	}else{
		cout<<"0";
		return 0;
	}
	return 0;
}

