#include<bits/stdc++.h>
using namespace std;
char a[10];
char b[10];
bool q=0,w=0,e=0,r=0;
int main(){
	freopen("travel.in","w",stdin);
	freopen("travel.out","s",stdout);
	cin>>a[0]>>a[1];
	cin>>b[0]>>b[1]; 
	cin>>a[2]>>a[3]>>a[4];  
	cin>>b[2]>>b[3]>>b[4];
	if(a[0]==b[0] && a[1]==b[1]){
		q=1;
	}else if(a[2]==b[2] && a[3]==b[3]){
		w=1;
	}else if(((a[4]=='D'||a[4]=='E')&&(b[4]=='D'||b[4]=='E'))||((a[4]=='A'||a[4]=='B'||a[4]=='C')&&(b[4]=='A'||b[4]=='B'||b[4]=='C'))){
		e=1;
	}else if(((a[4]=='D'||a[4]=='E')&&(b[4]=='D'||b[4]=='E'))||((a[4]=='A'||a[4]=='B')&&(b[4]=='A'||b[4]=='B'))||((a[4]=='C'||a[4]=='B')&&(b[4]=='C'||b[4]=='B'))){
		r=1;
	}
	if(q){
		cout<<1;
	}if(q && w){
		cout<<1;
	}if(q && w && e){
		cout<<1;
	}if(q && w && e && r){
		cout<<1;
	}
} 
