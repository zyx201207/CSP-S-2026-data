#include<iostream>
#include<string>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,r1,c2,r2;
	cin>>c1>>r1>>c2>>r2;
	if(c1==c2)cout<<1;
	else cout<<0;
	if(c1==c2 && r1[0]==r2[0] && r1[1]==r2[1]){
		cout<<1;
	}
	else cout<<0;
	if(c1==c2 && r1[0]==r2[0] && r1[1]==r2[1]){
		if(r1[2]>='D' && r2[2]>='D'){
			cout<<1;
		}
		else if(r1[2]<='C' && r2[2]<='C'){
			cout<<1;
		}
		else cout<<0;
	}
	else cout<<0;
	if(c1==c2 && r1[0]==r2[0] && r1[1]==r2[1]){
		if(r1[2]>='D' && r2[2]>='D'){
			cout<<1;
		}
		else if(r1[2]<='C' && r2[2]<='C'){
			cout<<(abs(r1[2]-r2[2])==1);
		}
		else cout<<0;
	}
	else cout<<0;
	return 0;
} 
