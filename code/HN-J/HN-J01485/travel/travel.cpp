#include<bits/stdc++.h>
using namespace std;
string a,a1,b,b1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>a1>>b>>b1;
	if(a==b){
		cout<<"1";
		string h;
		h+=a1[0];
		h+=a1[1];
		string s;
		s+=b1[0];
		s+=b1[1];
		char a2=a1[2],b2=b1[2];
		if(h==s){
			cout<<"1";
			if((a2<='C' and b2<='C')or(a2>'C' and b2>'C')){
				cout<<"1";
				if(char(a2+1)==b2||char(a2-1)==b2)
					cout<<"1";
				else{
					cout<<"0";
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
} 
