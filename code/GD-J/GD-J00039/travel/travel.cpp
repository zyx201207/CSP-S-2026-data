#include<iostream>
using namespace std;

string c1,s1,c2,s2;
string ans;
bool b1,b2,b3;

int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>c1>>s1>>c2>>s2;
	
	if(c1==c2){
		ans.push_back('1');
		b1=1;
	}else{
		ans.push_back('0');
	}
	
	if(b1&&s1[0]==s2[0]&&s1[1]==s2[1]){
		ans.push_back('1');
		b2=1;
	}else{
		ans.push_back('0');
	}
	
	if(b2&&(((s1[2]>='A'&&s1[2]<='C')&&(s2[2]>='A'&&s2[2]<='C'))||
	    ((s1[2]>='D'&&s1[2]<='E')&&(s2[2]>='D'&&s2[2]<='E')))){
		ans.push_back('1');
		b3=1;
	}else{
		ans.push_back('0');
	}
	
	if(b1&&b2&&b3&&abs(s1[2]-s2[2])==1){
		ans.push_back('1');
	} else {
		ans.push_back('0');
	}
	
	cout<<ans<<'\n';
	
	return 0;
} 
