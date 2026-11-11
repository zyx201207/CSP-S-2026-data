#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
long long int e,f,g,h;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	e=(b[0]-'0')*10+(b[1]-'0');
	f=(d[0]-'0')*10+(d[1]-'0');
	if(a==c){
		if(e==f){
			if(b[2]<='C' && d[2]<='C'){
				if(b[2]=='B' || d[2]=='B'){
					cout<<"1111";
				}else{
					cout<<"1110";
				}
			}else{
				if(b[2]>='D' && d[2]>='D'){
					cout<<"1111";
				}else{
					cout<<"1100";
				}
			}
		}else{
			cout<<"1000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
