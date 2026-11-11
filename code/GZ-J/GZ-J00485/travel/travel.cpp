//GZ-J00485 ³Â×ÓÐù
#include<bits/stdc++.h>
using namespace std;
int s,r,p1,p2;
char s1,r1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s>>p1>>s1>>r>>p2>>r1;
	if(s==r){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	
	
	
	if(p1==p2){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	
	
	if(s1=='A'){
		if(r1=='B'||r1=='C') cout<<1;
		else{
			cout<<"00";
			return 0;
		}
	}
	else if(s1=='B'){
		if(r1=='A'||r1=='C') cout<<1;
		else{
			cout<<"00";
			return 0;
		}
	}
	else if(s1=='C'){
		if(r1=='B'||r1=='A') cout<<1;
		else{
			cout<<"00";
			return 0;
		}
	}
	else if(s1=='D'){
		if(r1=='F') cout<<1;
		else{
			cout<<"00";
			return 0;
		}
	}
	else if(s1=='F'){
		if(r1=='D') cout<<1;
		else{
			cout<<"00";
			return 0;
		}
	}

	
	if(s1=='A'){
		if(r1=='B') cout<<1;
		else cout<<0;
	}
	else if(s1=='B'){
		if(r1=='A'||r1=='C') cout<<1;
		else cout<<0;
	}
	else if(s1=='C'){
		if(r1=='B') cout<<1;
		else cout<<0;
	}
	else if(s1=='D'){
		if(r1=='F') cout<<1;
		else cout<<0;
	}
	else if(s1=='F'){
		if(r1=='D') cout<<1;
		else cout<<0;
	}
	return 0;
}
