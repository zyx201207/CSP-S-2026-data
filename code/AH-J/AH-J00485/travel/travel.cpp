#include<bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4;
bool func(){
	
	return (c2[2]>='A'&&c2[2]<='C'&&c4[2]>='A'&&c4[2]<='C')||(c2[2]>='D'&&c2[2]<='E'&&c4[2]>='D'&&c4[2]<='E');
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>c3>>c4;
	int flag1=1;
	if(c1==c3){
		cout<<1;
	}else{
		cout<<0;
		flag1=0;
	}
	
	int flag2=1;
	if(c2[0]==c4[0]&&c2[1]==c4[1]&&flag1){
		cout<<1;
	}else{
		cout<<0;
		flag2=0;
	}
	
	bool flag3=1;
	if(func()&&flag2){
		cout<<1;
	}else{
		cout<<0;
		flag3=0;
	}
	
	if(abs(c2[2]-c4[2])==1&&flag3){
		cout<<1;
	}else cout<<0;
	return 0;
}
