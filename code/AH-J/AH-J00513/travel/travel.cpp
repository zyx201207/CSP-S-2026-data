#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		string a=s1.substr(0,2);
		string b=s2.substr(0,2);
		if(a==b){
			cout<<1;
			char c=s1[2];
			char d=s2[2];
			int x,y;
			if(c<='C'&&c>='A'){
				x=1;
			}else {
				x=0;
			}
			if(d<='C'&&d>='A'){
				y=1;
			}else{
				y=0;
			}
			if(x==y){
				cout<<1;
				if(abs(s1[2]-s2[2])==1){
					cout<<1;
				}else{
					cout<<0;
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
}
