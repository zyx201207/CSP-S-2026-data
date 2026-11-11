#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string a,b,x,y;
int ok=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>x>>y;
	//  02 01A 02 01B
	//1.
	if(a==x)cout<<1;
	else cout<<0;
	//2.
	if(a==x && b[0]==y[0] && b[1]==y[1]){
		cout<<1;
		ok=1;
	}else{
		cout<<0;
	}
	//3.
	if(ok==1 && int(b[2])>=65 && int(b[2])<=67 && int(y[2])>=65 && int(y[2])<=67){
		cout<<1;
		ok=2;
	}else if(ok==1 && (int(b[2])==68 || int(b[2])==69) && (int(y[2])==68 || int(y[2])==69)){
		cout<<1;
		ok=2;
	}else{
		cout<<0;
	}
	//4.
	if(ok==2 && (int(b[2])==int(y[2])-1 || int(b[2])==int(y[2])+1)){
		if(b[2]=='C' && y[2]=='D' || y[2]=='C' && b[2]=='D'){
			cout<<0;
		}else cout<<1; 
	}else cout<<0;
	return 0;
}
