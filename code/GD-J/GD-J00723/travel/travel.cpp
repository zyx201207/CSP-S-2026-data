#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
string ans;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	//同车厢 
	bool f=true;
	for(int i=0;i<2;i++){
		if(c1[i]!=c2[i]) f=false;
	}
	if(f==true) ans+='1';
	else ans+='0';
	//同排 
	bool f1=true;
	for(int i=0;i<2;i++){
		if(s1[i]!=s2[i]) f1=false;
	}
	if(f1==true&&f==true) ans+='1';
	else ans+='0';
	//同侧 
	bool f2=true;
	if(f1==true&&f==true){
		if(s1[2]<='C'&&s2[2]<='C'){
			ans+='1';
		}
		else if(s1[2]>='D'&&s2[2]>='D'){
			ans+='1';
		}
		else{
			ans+='0';
			f2=false;
		}
	}
	else{
		ans+='0';
		f2=false;
	}
	//相邻
	if(f2==true&&f1==true&&f==true){
		if(s1[2]-s2[2]==1||s2[2]-s1[2]==1){
			ans+='1';
		}
		else ans+='0';
	}
	else{
		ans+='0';
	}
	for(int i=0;i<4;i++){
		cout<<ans[i];
	}
	return 0;
}
