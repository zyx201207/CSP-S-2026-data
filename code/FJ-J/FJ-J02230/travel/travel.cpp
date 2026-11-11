#include<bits/stdc++.h>
using namespace std;
string a,b,c,d,s;
bool A(char a,char b){
	if(a<='C'&&b<='C') return 1;
	if(a>='D'&&b>='D') return 1;
	return 0;
}
bool B(char a,char b){
	if(a=='C'&&b=='D') return 0;
	if(a=='D'&&b=='C') return 0;
	if(a-b==1||a-b==-1){
		return 1;
	}
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c) {
		s+='1';
		if(b[0]==d[0]&&b[1]==d[1]){
			s+='1';
			if(A(b[2],d[2])){
				s+='1';
				if(B(b[2],d[2])){
					s+='1';
				}else{
					s+='0';
				}
			}
			else{
				s+="00";
			}
		}else{
			s+="000";
		}
	}else{
		cout<<"0000";
		return 0;
	}
	cout<<s;
}


