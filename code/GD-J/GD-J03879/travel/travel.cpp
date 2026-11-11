#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout <<1;
		string n,m;
		n=s1.substr(0,2);
		m=s2.substr(0,2);
		if(n==m){
			cout <<1;
			char a=s1[2];
			char b=s2[2];
			if((a>='A' && a<='C' && b>='A' && b<='C') || (a>='D' && a<='F' && b>='D' && b<='F')){
				cout <<1;
				if(abs(a-b)==1){
					cout <<1;
				}
				else cout <<0;
			}
			else cout <<"00";
		}
		else cout <<"000";
	}
	else cout <<"0000";
	return 0;
}
