#include <iostream>
using namespace std;
string c1,s1,c2,s2;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	bool abc[3]={0,0,0},ef[3]={0,0,0};
	if(c1==c2) cout<<1;
	else{
		for(int i=1;i<=4;i++) cout<<0;
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1])cout<<1;
	else{
		for(int i=1;i<=3;i++) cout<<0;
		return 0;
	}
	if(s1[2]=='F'||s1[2]=='D'){
		ef[1]=1;
	}
	if(s2[2]=='F'||s2[2]=='D'){
		ef[2]=1;
	}
	if(ef[1]==ef[2]){
		cout<<1;
	}else{
		for(int i=1;i<=2;i++)cout<<0;
		return 0;
	}
	if(s1[2]-s2[2]==1||s2[2]-s1[2]==1) cout<<1;
	else cout<<0;
	return 0;
}
