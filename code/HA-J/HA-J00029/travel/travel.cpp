#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;

	string pai1;
	pai1+=s1[0];pai1+=s1[1];
	string pai2;
	pai2+=s2[0];pai2+=s2[1];
	char d1=s1[2];
	char d2=s2[2];
	if(c1==c2){
		cout<<1;	
	}else{
		cout<<"0000";
		return 0;
	}
	if(pai1==pai2){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if((d1>='A'&&d1<='C')&&(d2>='A'&&d2<='C')){
		cout<<1;
		if(abs(d1-d2)==1){
			cout<<1;
		}else{
			cout<<0;
		}
	}else if((d1>='D'&&d1<='F')&&(d2>='D'&&d2<='F')){
		cout<<1;
			if(abs(d1-d2)==1){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<"00";
		return 0;
	}
	return 0;
	//Trick||Treat!
}
