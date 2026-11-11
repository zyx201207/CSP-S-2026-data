//GZ-J00724 ¹ğçùÏè 
#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a[0]==c[0] && a[1]==c[1]){
		cout<<1;
	}else{
		cout<<0;
	}
	if((a[0]==c[0] && a[1]==c[1]) && (b[0]==d[0] && b[1]==d[1])){
		cout<<1;
	}else{
		cout<<0;
	}
	if((a[0]==c[0] && a[1]==c[1]) && (b[0]==d[0] && b[1]==d[1]) && (((int(b[2])<=67 && int(b[2])>=65) && (int(d[2])<=67 && int(d[2])>=65) || ((int(b[2])==68 && int(d[2])==70) || (int(b[2])==70 && int(d[2])==68))))){
		cout<<1;
	}else{
		cout<<"00";
	}
	if((a[0]==c[0] && a[1]==c[1]) && (b[0]==d[0] && b[1]==d[1]) && (((int(b[2])<=67 && int(b[2])>=65) && (int(d[2])<=67 && int(d[2])>=65) || ((int(b[2])==68 && int(d[2])==70) || (int(b[2])==70 && int(d[2])==68))))){
		if((int(b[2])<=67 && int(b[2])>=65) && (int(d[2])<=67 && int(d[2])>=65)){
			if(int(b[2])==65 && int(d[2])==66){
				cout<<1;
			}else if(int(b[2])==66 && int(d[2])==67){
				cout<<1;
			}else if(int(b[2])==67 && int(d[2])==66){
				cout<<1;
			}else if(int(b[2])==66 && int(d[2])==65){
				cout<<1;
			}else{
				cout<<0;
			}
		}else{
			cout<<1;
		}
	}
	return 0;
}
