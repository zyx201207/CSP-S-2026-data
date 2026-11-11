#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,a2,b1,b2;
	int n=0,m=0;
	cin>>a1>>a2>>b1>>b2;
	if(a1[0]==b1[0]&&a1[1]==b1[1]){
		cout<<1;
		m++;
	}
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(a2[0]==b2[0]&&a2[1]==b2[1]){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(a2[0]==b2[0]&&a2[1]==b2[1]){
		if(a2[2]=='A'||a2[2]=='B'||a2[2]=='C'){
			if(b2[2]=='A'||b2[2]=='B'||b2[2]=='C'){
				cout<<1;
				n++;
			}
		}
		if(a2[2]=='D'||a2[2]=='F'){
			if(b2[2]=='D'||b2[2]=='F') {
				cout<<1;
				n++;
			}
		}
		if(n==0){
			cout<<n;
		}
	}
	else{
		cout<<0;
	}
	if(n==1&&m==1){
		if(a2[1]+1==b2[1]+0||a2[1]-1==b2[1]+0||a2[2]-1==b2[2]+0||a2[2]+1==b2[2]+0){
			cout<<1;
		}
		else cout<<0;
	}
	else cout<<0;
}
