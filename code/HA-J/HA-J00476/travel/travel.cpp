#include<bits/stdc++.h>
using namespace std;
//ÎÄ¼ş²Ù×÷  long long 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	string ans="",e1=s1.substr(2,2),e2=s2.substr(2,2);
	if(c1==c2){
		ans+="1";
	}
	else if(c1!=c2){
		ans+="0";
	}
	if(s1.substr(0,2)==s2.substr(0,2)&&c1==c2){
		ans+="1";
	}
	else{
		ans+="0";
	}
	if(s1.substr(0,2)==s2.substr(0,2)&&c1==c2){
		if(e1=="A"){
			if(e2=="B"||e2=="C"){
				ans+="1";
			}
			else{
				ans+="0";
			}
		}
		else if(e1=="B"){
			if(e2=="A"||e2=="C"){
				ans+="1";
			}
			else{
				ans+="0";
			}
		}
		else if(e1=="C"){
			if(e2=="B"||e2=="A"){
				ans+="1";
			}
			else{
				ans+="0";
			}
		}
		else if(e1=="D"&&e2=="F"||e1=="F"&&e2=="D"){
			ans+="1";
		}
		else{
			ans+="0";
		}
	}
	else{
		ans+="0";
	}
	if(c1==c2&&s1.substr(0,2)==s2.substr(0,2)){
		if(e1=="A"&&e2=="B"){
			ans+="1";
		}
		else if(e1=="B"&&e2=="A"){
			ans+="1";
		}
		else if(e1=="F"&&e2=="D"){
			ans+="1";
		}
		else if(e1=="D"&&e2=="F"){
			ans+="1";
		}
		else if(e1=="C"&&e2=="B"){
			ans+="1";
		}
		else if(e1=="B"&&e2=="C"){
			ans+="1";
		}
		else{
			ans+="0";
		}
	}
	else{
		ans+="0";
	}
	cout<<ans;
	return 0;
}
