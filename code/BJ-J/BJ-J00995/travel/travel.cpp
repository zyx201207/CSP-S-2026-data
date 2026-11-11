#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int f1=0,f2=0,f3=0;
	int a1,b1,b2,a2,a3,b3;
	string a,b;
	cin>>a1>>a>>b1>>b;
	if(a1!=b1){
		cout<<"0000";
		return 0;
	}
	a2=a[0]-'0';
	b2=b[0]-'0';	
	a2=a2*10+(a[1]-'0');
	b2=b2*10+(b[1]-'0');
	a3=a[2]-'A'+1;
	b3=b[2]-'A'+1;
	if(a2==b2){
		f1=1;
	}if((a3<=3&&b3<=3)||(a3>=4&&b3>=4)){
		f2=1;
	}if(((a3<=3&&b3<=3)||(a3>=4&&b3>=4))&&(max(a3,b3)-min(a3,b3)==1)){
		f3=1;
	}
	cout<<1;
	if(f1==0){
		cout<<"000";
	}else if(f2==0){
		cout<<"100";
	}else if(f3==0){
		cout<<"110";
	}else{
		cout<<"111";
	}
	return 0;
}