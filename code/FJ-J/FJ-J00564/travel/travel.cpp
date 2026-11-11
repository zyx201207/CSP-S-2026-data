#include <bits/stdc++.h>
using namespace std;
string bc,bs,ec,es;
bool ck(char a,char b){
	if(a>='A'&&a<='C'&&b<='C'&&b>='A'||a>='D'&&a<='F'&&b<='F'&&b>='D') return 1;
	return 0;
}
bool ch(char a,char b){
	if(a=='C'&&b=='D'||a=='D'&&b=='C') return 0;
	if(abs(int(a)-int(b))==1) return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>bc>>bs>>ec>>es;
	string x=bs.substr(0,2);
	string y=es.substr(0,2);
	char a=bs[bs.size()-1];
	char b=es[es.size()-1];
	if(bc==ec){
		cout<<1;
		if(x==y){
			cout<<1;
			if(ck(a,b)){
				cout<<1;
				if(ch(a,b)){
					cout<<1;
				}
				else cout<<0;
			}
			else{
				cout<<"00";
				return 0;
			}
		}
		else{
			cout<<"000";
			return 0;
		}
	}
	else{
		cout<<"0000";
		return 0;
	}
	return 0;
} 
