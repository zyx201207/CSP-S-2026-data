#include<iostream>
#include<cmath>
#include<string>
using namespace std;
string c[3],s[3];
bool check1(){
	return (s[1][2]<='C'&&s[1][2]>='A'&&s[2][2]<='C'&&s[2][2]>='A');
}
bool check2(){
	return (s[1][2]<='F'&&s[1][2]>='D'&&s[2][2]<='F'&&s[2][2]>='D');
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=1;i<=2;i++){
		cin>>c[i]>>s[i];
	}
	if(c[1]==c[2]){
		cout<<"1";
		if(s[1][0]==s[2][0]&&s[1][1]==s[2][1]){
			cout<<"1";
			if(check1()||check2()){
				cout<<"1";
				if(abs(int(s[1][2]-s[2][2]))==1){
					cout<<"1";
				}
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	cout<<'\n';
	return 0;
} 
