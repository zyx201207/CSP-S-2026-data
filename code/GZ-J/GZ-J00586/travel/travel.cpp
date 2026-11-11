//贵州省六盘水市第三中学 刘宇帆 GJ-J00586 
#include<bits/stdc++.h>
using namespace std;
string a,a1,b,b1;
int main(){ 
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>a1;
	cin>>b>>b1;
	if(a==b)cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	
	if(a1[1]==b1[1]&&a1[0]==b1[0]){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	
	if(a1[2]<='C'&&b1[2]<='C'){
		cout<<1;
	}else if(a1[2]>='D'&&b1[2]>='D'){
		cout<<"11";
		return 0;
	}else {
		cout<<"00";
		return 0;
	}
	if(a1[2]=='B'||b1[2]=='B'){
		cout<<1;
	}else cout<<0;
	return 0;
} 
