#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	int bs,ds;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<'1';
		if((b[0]-'0')*10+b[1]-'0'==(d[0]-'0')*10+d[1]-'0'){
			cout<<'1';
			ds=d[2]-'A';
			bs=b[2]-'A';
			if(ds>2 && bs>2){
				cout<<"11";
			}else if(ds<3 && bs<3){
				cout<<'1';
				if(abs(bs-ds)==1){
					cout<<'1';
				}else{
					cout<<'0';
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
