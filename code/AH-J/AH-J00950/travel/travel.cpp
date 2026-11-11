#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(b[2]<='C'){
		b+='1';
	}else{
		b+='2';
	}
	if(d[2]<='C'){
		d+='1';
	}else{
		d+='2';
	}
	if(a==c){
		cout<<1;
		if(b[0]==d[0]&&b[1]==d[1]){
			cout<<"1";
			if(b[3]==d[3]){
				cout<<"1";
				long long q;
				q=(long long)b[2]-d[2];
				if(abs(q)==1){
					cout<<"1";
				}else{
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
