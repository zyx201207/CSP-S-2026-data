#include <bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int pai1=(s1[0]-'0')*10+s1[1]-'0';
	int pai2=(s2[0]-'0')*10+s2[1]-'0';
	int zuo1=s1[2]-'A';
	if(zuo1==5) zuo1--;
	int zuo2=s2[2]-'A';
	if(zuo2==5) zuo2--;
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
	if((zuo1<=2&&zuo2<=2)||(zuo1>=3&&zuo2>=3)){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if(abs(zuo1-zuo2)==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
