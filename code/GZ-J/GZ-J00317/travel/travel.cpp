//GZ-J00317 遵义市第四初级中学 王培祯 
#include <bits/stdc++.h>
using namespace std;
int c1,c2;
char s1[4],s2[4];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
	}
	else{
		cout<<"0000";
		return 0;
	}
	int a=(s1[0]-'0')*10+(s1[1]-'0'),b=(s2[0]-'0')*10+(s2[1]-'0');
	if(a==b){
		cout<<"1";
	}
	else{
		cout<<"000";
		return 0;
	}
	int a1=s1[2]-'A',b1=s2[2]-'A';
	if((a1<=2&&b1<=2)||(a1>2&&b1>2)){
		cout<<"1";
	}
	else{
		cout<<"00";
		return 0;
	}
	if(a1-b1==1||b1-a1==1){
		cout<<"1";
	}
	else{
		if((a1==3&&b1==5)||(a1==5&&b1==3)){
			cout<<"1";
			return 0;
		}
		cout<<"0";
	}
	return 0;
}

