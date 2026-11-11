#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
string a,b;
char c,d;
int main(){
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
	}
	else{
		cout<<"0000";
		return 0;
	}
	for(int i=1;i<=(int)s1.size();i++){
		if(s1[i]>='0'&&s1[i]<='9'){
			a+=s1[i];
		}
		else if(s1[i]>='A'&&s1[i]<='F'){
			c=s1[i];
		}
	} 
	for(int i=1;i<=(int)s2.size();i++){
		if(s2[i]>='0'&&s2[i]<='9'){
			b+=s2[i];
		}
		else if(s2[i]>='A'&&s2[i]<='F'){
			d=s2[i];
		}
	} 
	if(a==b){
		cout<<"1";
	}
	else{
		cout<<"000";
		return 0;
	}
	if(c=='D'&&d=='F'||c=='D'&&d=='F'){
		cout<<"11";
	}
	else if(c>='A'&&c<='C'&&d>='A'&&d<='C'){
		cout<<"1";
		if(c==d+1||d==c+1){
			cout<<"1";
		}
		else{
			cout<<"0";
		}
	}
	else{
		cout<<"000";
	}
	
	return 0;
	
}
