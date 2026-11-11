#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>c2>>s1>>s2;
	if(c1==s1){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(c2[0]==s2[0]&&c2[1]==s2[1]){
		cout<<1; 
	}
	else{
		cout<<"000";
		return 0;
	}
	if('A'<=c2[2]&&c2[2]<='C'&&'A'<=s2[2]&&s2[2]<='C'){
		cout<<1;
		if(int(c2[2])+1==int(s2[2])||(int(c2[2])-1==int(s2[2]))){
			cout<<1;
		}
		else{
			cout<<0;
			return 0;
		}
	}
	else if(c2[2]=='D'&&s2[2]=='F'||(c2[2]=='F'&&s2[2]=='D')){
		cout<<11; 
	}
	else{
		cout<<"00";
		return 0;
	}
	
} 
