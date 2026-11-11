#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	int a1=(s1[0]-'0')*10+s1[1]-'0';
	int a2=(s2[0]-'0')*10+s2[1]-'0';
	if(a1==a2){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	int b1=s1[2]-'A';
	int b2=s2[2]-'A';
	if((b1<3&&b2<3)||(b1>=3&&b2>=3)){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if(b1-1==b2||b2-1==b1){
		cout<<1;
	}else if((b1==3&&b2==5)||(b1==5&&b2==3)){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
