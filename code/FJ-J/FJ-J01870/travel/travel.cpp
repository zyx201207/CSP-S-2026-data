#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a!=c){
		cout<<"0000";
	}
	else{
		if(b[0]==d[0]&&b[1]==d[1]){
			char aa,bb;
			aa=b[2];
			bb=d[2];
			if((aa<='C'&&aa>='A'&&bb<='C'&&bb>='A')||(aa<='F'&&aa>='D'&&bb<='F'&&bb>='D')){
				if(aa=='A'&&bb=='B'){
					cout<<"1111";
				}
				else if(aa=='B'&&bb=='A'){
					cout<<"1111";
				}
				else if(aa=='B'&&bb=='C'){
					cout<<"1111";
				}
				else if(aa=='C'&&bb=='B'){
					cout<<"1111";
				}
				else if(aa=='D'&&bb=='F'){
					cout<<"1111";
				}
				else if(aa=='F'&&bb=='D'){
					cout<<"1111";
				}
				else{
					cout<<"1110";
				}
			}
			else{
				cout<<"1100";
			}
		}
		else{
			cout<<"1000";
		}
	}
	return 0;
}
