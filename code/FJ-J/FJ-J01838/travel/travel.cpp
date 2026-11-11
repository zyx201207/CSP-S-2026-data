#include<bits/stdc++.h>
using namespace std;
string b,d;
int a,c,e,f;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	for(int i = 0;i<=1;i++){
		e=e*10+b[i]-'0';
		f=f*10+d[i]-'0';
	}
	if(a==c){
		cout<<"1";
		if(e==f){
			cout<<"1";
			if((b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C')||(b[2]>='D'&&b[2]<='E'&&d[2]>='D'&&d[2]<='E')){
				cout<<"1";
				if(b[2]-d[2]==1||d[2]-b[2]==1){
					cout<<"1";
					return 0;
				}
				cout<<"0";
				return 0;
			}
			cout<<"00";
			return 0;
		}
		cout<<"000";
		return 0;
	}
	cout<<"0000";
	return 0;
} 
