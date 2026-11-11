#include<bits/stdc++.h> 
using namespace std;

int a[20][10];
string rc,rs,xc,xs;
string s;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> rc >> rs >> xc >> xs;
	if(rc==xc){
		s=s+'1';
		if(rs[1]==xs[1]&&rs[0]==xs[0]){
			s=s+'1';
			if((rs[2]<='C'&&xs[2]<='C')||(rs[2]>'C'&&xs[2]>'C')){
				s=s+'1';
				if(abs((int)rs[2]-xs[2])<=1){
					s=s+'1';
				}else{
					s=s+'0';
				}
			}else{
				s=s+"00";
			}
		}else{
			s=s+"000";
		}
	}else{
		s="0000";
	}
	cout << s;
	
	
	
	return 0;
}
