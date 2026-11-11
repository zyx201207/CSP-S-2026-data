#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int a=int(s1[0]-'0')+int(s1[1]-'0');
	int b=int(s2[0]-'0')+int(s2[1]-'0');
	if(c1==c2)cout<<"1";
	else {
		cout<<"0000";
		return 0;
	}
	if(a==b)cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	char c=s1[2],d=s2[2];
	if(c=='F'&&d=='D'||c=='D'&&d=='F'){
		cout<<"1";
	}else if(c=='C'&&d=='B'||c=='C'&&d=='A'||c=='B'&&d=='C'||c=='B'&&d=='A'||c=='A'&&d=='C'||c=='A'&&d=='B'){
		cout<<"1";
	}else{
		cout<<"00";
		return 0;
	}
	if(c=='F'&&d=='D'||c=='D'&&d=='F'){
		cout<<"1";
	}else if(c=='C'&&d=='B'||c=='B'&&d=='C'||c=='B'&&d=='A'||c=='A'&&d=='B'){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
} 
