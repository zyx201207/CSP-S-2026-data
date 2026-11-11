#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d,e;
	cin>>a>>b>>c>>d;
	if(a==c){
		e+='1';
		if(b[0]==d[0]&&b[1]==d[1]){
			e+='1';
			if(b[2]>='A'&&d[2]<='C'){
				e+='1';
				if(b[2]-1==d[2]-0||b[2]+1==d[2]-0){
					e+='1';
					cout<<e;
				}else{
					cout<<e<<'0';
				}
			}
			else if(b[2]>='D'&&d[2]<='F'){
				e+='1';
				cout<<e<<'1';
				
			}else{
				cout<<e<<"00";
				return 0;
			}
		}
		else{
			cout<<e<<"000";
			return 0;
		}
	}else{
		cout<<"0000";
		return 0;
	}
}
