#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b;
	bool q1=0,q2=0,q3=0,q4=0;
	ll n,m;
	cin>>n>>a>>m>>b;
	if(n==m){
	q1=1;
	if(a[0]==b[0]&&a[1]==b[1]){
	q2=1;
	switch(a[2]){
		case 'A':{
			if(b[2]=='B'||b[2]=='C')q3=1;
			if(b[2]=='B')q4=1;
			break;
		}
		case 'B':{
			if(b[2]=='A'||b[2]=='C')q3=1; q4=1;
			break;
		}
		case 'C':{
			if(b[2]=='B'||b[2]=='A')q3=1;
			if(b[2]=='B')q4=1;
			break;
		} 
		case 'D':{
			if(b[2]=='F')q3=1; q4=1;
			break;
		}
		case 'F':{
			if(b[2]=='D')q3=1; q4=1;
			break;
		}
	}
}
}
	cout<<q1<<q2<<q3<<q4;
	return 0;
} 
