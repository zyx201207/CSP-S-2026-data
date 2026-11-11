#include<bits/stdc++.h>
using namespace std;
struct node{
	string a,s;
}n[100001];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n[1].a>>n[1].s>>n[2].a>>n[2].s;
	if(n[1].a==n[2].a){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(n[1].s[1]==n[2].s[1]){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	char a1,s1;
	a1=n[1].s[2];
	s1=n[2].s[2];
	if((a1=='A'||a1=='B'||a1=='C')&&(s1=='A'||s1=='B'||s1=='C')){
		cout<<1;
	}
	else if((a1=='D'||a1=='F')&&(s1=='D'||s1=='F')){
		cout<<1;
	}
	else{
		cout<<"00";
		return 0;
	}
	if(a1+1==s1||a1-1==s1){
		cout<<1;
	}
	else{
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
