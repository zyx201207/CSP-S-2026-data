#include<bits/stdc++.h>
using namespace std;
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
string c1,s1,c2,s2;
int x=1;
int max(int a,int b){
	if(a>b) return a;
	return b;
}
int main(){
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<max(c1.size(),c2.size());i++){
		if(c1[i]!=c2[i]){
			x=0;
			break;
		}
	}
	cout<<x;
	if(s1[0]==s2[0] && s1[1]==s2[1]){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(s1[2]=='F' && s2[2]=='D'){
		cout<<1;
	}
	else if(s1[2]=='D' && s2[2]=='F'){
		cout<<1;
	}
	else if(s1[2]=='A' && s2[2]=='B'){
		cout<<1;
	}
	else if(s1[2]=='A' && s2[2]=='C'){
		cout<<1;
	}
	else if(s1[2]=='B' && s2[2]=='C'){
		cout<<1;
	}
	else if(s1[2]=='B' && s2[2]=='A'){
		cout<<1;
	}
	else if(s1[2]=='C' && s2[2]=='A'){
		cout<<1;
	}
	else if(s1[2]=='C' && s2[2]=='B'){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(s1[2]=='F' && s2[2]=='D'){
		cout<<1;
	}
	else if(s1[2]=='D' && s2[2]=='F'){
		cout<<1;
	}
	else if(s1[2]=='A' && s2[2]=='B'){
		cout<<1;
	}
	else if(s1[2]=='B' && s2[2]=='A'){
		cout<<1;
	}
	else if(s1[2]=='B' && s2[2]=='C'){
		cout<<1;
	}
	else if(s1[2]=='C' && s2[2]=='B'){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
} 
