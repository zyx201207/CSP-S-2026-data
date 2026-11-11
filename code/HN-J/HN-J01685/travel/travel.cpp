#include<bits/stdc++.h>
using namespace std;
string a;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		a="0000";
	}else{
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			if(s1[2]=='D'&&s2[2]=='F'){
			a="1111";
		    }else if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')){
			a="1111";
		    }else if(s1[2]=='A'&&s2[2]=='C'){
		    	a="1110";
			}else{
				a="1100";
			}
		}else{
			a="1000";
		}
	}
	cout<<a;
	return 0;
} 
