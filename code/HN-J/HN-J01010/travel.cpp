#include<bits/stdc++.h>
using namespace std;
int main(){
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
char a1[100000],a3[10000],a2[10000],a4[10000];
cin>>a1[1]>>a2[2]>>a3[1]>>a4[2];
	
	if(a1[0]==a3[0]&&a1[1]==a3[1]){ 
		cout<<1;
	}
	else
	cout<<0;
	if(a2[0]==a4[0]&&a2[1]==a4[1]){
		cout<<1;
	}
	else
	cout<<0;
	if(a2[0]==a4[0]&&a2[1]==a4[1]&&a2[2]=='A'&&a4[2]=='B'||a2[2]=='B'&&a4[2]=='A'||a2[2]=='B'&&a4[2]=='C'||a2[2]=='C'&&a4[2]=='B'||a2[2]=='D'&&a4[2]=='F'||a2[2]=='F'&&a4[2]=='D'){
		cout<<1<<1;
	}
	else if(a2[0]==a4[0]&&a2[1]==a4[1]&&a2[2]=='A'&&a4[2]=='C'||a2[2]=='C'&&a4[2]=='A'){
		cout<<1<<0;

}
	else
	cout<<0<<0;

	return 0;
} 
