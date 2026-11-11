#include<iostream>
#include<string>
using namespace std;
string c1,s1,c2,s2; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<"0000\n";
		return 0;
	}
	string a=s1.substr(0,2);char b=s1[2];
	string c=s2.substr(0,2);char d=s2[2];
	if(a==c){
		cout<<1;
		if((b<='C'&&d<='C')||(b>'C'&&d>'C')){
			cout<<1;
			if(abs(b-d)==1||(b=='D'&&d=='F')||(b=='F'&&d=='D')){
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
	cout<<'\n';
	return 0;
}
