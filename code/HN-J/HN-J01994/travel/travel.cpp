#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >>c1>>s1>>c2>>s2;
	string q;
	q="0000";
	if(c1==c2){
		q="1000";
	
	}else {
		cout <<q;
		return 0;
}
if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]){
			q="1100";
if (s1[2]=='D'||s1[2]=='E'){
if(s2[2]=='D'||s2[2]=='E'){
	q="1111";
}
else {

q="1100";
}


}
else if(s1[2]=='B'||s1[2]=='A'||s1[2]=='C'){
if(s2[2]=='B'||s2[2]=='A'||s2[2]=='C'){
	q="1110";
	if (s1[2]=='B'){
		q="1111";
		
	}
	else if(s2[2]=='B'){
	q="1111";
	
	}
	else {
		q="1110";
	
	}
}
	

else 
{
	q="1100";

}}
}
else {
		q="1000";
	
}
cout <<q;
return 0;
} 
