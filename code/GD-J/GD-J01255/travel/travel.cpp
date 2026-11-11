#include<bits/stdc++.h>
using namespace std;
bool cx(string a1,string a2,string b1,string b2){
	return a1==b1;
}
bool tp(string a1,string a2,string b1,string b2){
	if(cx(a1,a2,b1,b2)){
		return (a2[0]==b2[0])&&a2[1]==b2[1];
	}
	return false;
}
bool tc(string a1,string a2,string b1,string b2){
	if(tp(a1,a2,b1,b2)){
		if((a2[2]=='A'||a2[2]=='B'||a2[2]=='C')&&(b2[2]=='A'||b2[2]=='B'||b2[2]=='C')){
			return true;
		}else if((a2[2]=='D'||a2[2]=='F')&&(b2[2]=='D'||b2[2]=='F')){
			return true;
		}else{
			return false;
		}
	}
	return false;
}
bool pb(string a1,string a2,string b1,string b2){
	if(tc(a1,a2,b1,b2)){
		char la,lb;
		la=a2[2],lb=b2[2];
		if((la==lb+1)||(la==lb-1)){
			return true;
		}else{
			return false;
		}
	}
	return false;
}
int  main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	cout<<cx(c1,s1,c2,s2);
	cout<<tp(c1,s1,c2,s2);
	cout<<tc(c1,s1,c2,s2);
	cout<<pb(c1,s1,c2,s2);
	return 0;
} 
