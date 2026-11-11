#include<iostream>
using namespace std;
string c1,s1,c2,s2;
bool flag=true;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	for(int i=0;i<2;i++){
		if(s1[i]!=s2[i]){
			flag=false;
		}
	}
	if(flag){
		cout<<1;
	}else{
		cout<<0<<0<<0;
		return 0;
	}
	if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')){
		cout<<1;
	}else{
		cout<<0<<0;
		return 0;
	}
	if(s1[2]-s2[2]==1||s2[2]-s1[2]==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
