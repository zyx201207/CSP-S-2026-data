#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string bb,dd;
	int a,c,d,b;
	cin>>a>>bb>>c>>dd;
	if(a==c){
		cout<<"1";
	}
	else{
		cout<<"0000";
		return 0;
	}
	b=(bb[0]-'0')*100+(bb[1]-'0')*10+bb[2]-'A'+1;
	d=(dd[0]-'0')*100+(dd[1]-'0')*10+dd[2]-'A'+1;
	if(d/10==b/10){
		cout<<"1";
	}
	else{
		cout<<"000";
		return 0;
	}
	if((d%10<=3&&b%10<=3)||(d%10>3&&b%10>3)){
		cout<<"1";
	}
	else{
		cout<<"00";
		return 0;
	}
	if(abs(d%10-b%10)==1)cout<<"1";
	else cout<<"0";
	return 0;
}
