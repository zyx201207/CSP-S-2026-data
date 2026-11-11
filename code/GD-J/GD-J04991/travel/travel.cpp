#include<bits/stdc++.h> 
using namespace std;
struct aaa{
	int a1,a2,b1,b2;
	char c1,c2;
}a;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	//int a;char b;cin>>a>>b;cout<<a<<endl<<b;
	cin>>a.a1>>a.b1>>a.c1>>a.a2>>a.b2>>a.c2;
	if(a.a1==a.a2){
		cout<<"1";
	}
	 else {
	 cout<<"0000";return 0;}
	if(a.b1==a.b2) cout<<"1";
	 else {
	 cout<<"000";return 0;}
	if(((a.c1=='A'||a.c1=='B'||a.c1=='C')&&(a.c2=='A'||a.c2=='B'||a.c2=='C'))||((a.c1=='D'||a.c1=='F')&&(a.c2=='D'||a.c2=='F'))) cout<<"1";
	 else {
	 cout<<"00";return 0;}
	if(((a.c1=='D'||a.c1=='F')&&(a.c2=='D'||a.c2=='F'))||(a.c1=='B'||a.c2=='B')) cout<<"1";
	else cout<<"0";
	return 0;
	}
