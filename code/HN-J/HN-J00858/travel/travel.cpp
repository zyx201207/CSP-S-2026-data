#include<bits/stdc++.h> 
using namespace std;
string c1,s1,c2,s2;
string ans1,ans2,ans3,ans4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		ans1="1";
	}else{
		ans1="0";
	}
	string a1=s1.substr(0,2);
	string a2=s2.substr(0,2);
	if(a1==a2 && ans1=="1"){
		ans2="1";
	}else{
		ans2="0";
	}
	char b1=s1[2];
	char b2=s2[2];
	if(ans2=="1"&&(b1<='C'&&b2<='C' || b1>'C' && b2>'C')){
		ans3="1";
	}else{
		ans3="0";
	}
	if(abs(b1-b2)==1 && ans3=="1"){
		ans4="1";
	}else{
		ans4="0";
	}
	cout<<ans1<<ans2<<ans3<<ans4;
	return 0;
}
