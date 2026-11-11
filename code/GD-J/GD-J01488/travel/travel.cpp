#include<iostream>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>c2>>s1>>s2;
	if(c1!=s1){
		cout<<"0000"<<endl;
		return 0;
	}else{
		cout<<"1";
	}
	if(c2[0]==s2[0]&&c2[1]==s2[1]){
		cout<<"1";
	}else{
		cout<<"000"<<endl;
		return 0;
	}
	int a=c2[2]-'A';
	int b=s2[2]-'A';
	if((a<3&&b<3)||(a>2&&b>2)){
		cout<<"1";
	}else{
		cout<<"00"<<endl;
		return 0;
	}
	if(abs(a-b)==1){
		cout<<"1"<<endl;
	}else{
		cout<<"0"<<endl;
	}
	return 0;
}
