#include<bits/stdc++.h>
using namespace std;
string s,a,b,c,d; 
int id;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	getline(cin,s);
	for(int i=0;i<s.size();i++){
		if(s[i]!=' ')a=a+s[i];
		else{
			id=i;
			break;
		}
	}
	for(int i=id+1;i<s.size();i++){
		if(s[i]!=' ')b=b+s[i];
		else{
			id=i;
			break;
		}
	}
	for(int i=id+1;i<s.size();i++){
		if(s[i]!=' ')c=c+s[i];
		else{
			id=i;
			break;
		}
	}
	for(int i=id+1;i<s.size();i++){
		if(s[i]!=' ')d=d+s[i];
		else{
			id=i;
			break;
		}
	}
	if(a==c)cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	int x=(b[0]-'0')*10+(b[1]-'0'),y=(d[0]-'0')*10+(d[1]-'0');
	if(x==y)cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if(b[2]=='A'||b[2]=='B'||b[2]=='C'){
		if(d[2]=='A'||d[2]=='B'||d[2]=='C')cout<<1;
		else{
			cout<<"00";
			return 0;
		}
	}else if(b[2]=='D'||b[2]=='F'){
		if(d[2]=='D'||d[2]=='F'){
			cout<<"11";
			return 0;
		}else{
			cout<<"00";
			return 0;
		}
	}
	if(b[2]=='A'&&d[2]=='B')cout<<1;
	else if(b[2]=='B'&&d[2]=='C')cout<<1;
	else cout<<0;
	return 0;
}
