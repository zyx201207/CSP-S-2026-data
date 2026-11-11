#include<bits/stdc++.h>
using namespace std;
bool edg(char s1,char s2){
	if(s1=='A'&&s2=='B')return 1;
	if(s1=='A'&&s2=='C')return 1;
	if(s1=='A'&&s2=='A')return 1;
	if(s1=='B'&&s2=='B')return 1;
	if(s1=='B'&&s2=='C')return 1;
	if(s1=='B'&&s2=='A')return 1;
	if(s1=='C'&&s2=='B')return 1;
	if(s1=='C'&&s2=='C')return 1;
	if(s1=='C'&&s2=='A')return 1;
	if(s1=='D'&&s2=='F')return 1;
	if(s2=='D'&&s1=='F')return 1;
	return 0;
}
bool Zmjjkk_cxy(char s1,char s2){
	if(s1=='D'||s2=='D')return 1;
	if(s1=='B'||s2=='B')return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen ("travel.out","w",stdout);
	int n,m,a,k;
	char s1,s2;
	cin>>n>>a>>s1>>m>>k>>s2;
	if(n==m)cout<<1;
	else {cout<<"0000";return 0;}
	if(a==k)cout<<1;
	else {cout<<"000";return 0;}
	if(edg(s1,s2))cout<<1;
	else {cout<<"00";return 0;}
	if(Zmjjkk_cxy(s1,s2))cout<<1;
	else cout<<'0';
	return 0;
}
//put your hands up for yixiafanshang hewoxdzaidixiazhang
//KSKBL ZDJD WKZKBL
//ganjueburu Zmjjkk
