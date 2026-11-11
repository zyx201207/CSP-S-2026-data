#include<bits/stdc++.h>
using namespace std;
string r_csh,r_zwh,x_csh,x_zwh;
int r_p,x_p;
int turn_number(string s){
	int x=0;
	x=(s[0]-'0')*10+(s[1]-'0');
	return x;
}
bool pd1(char a,char b){
	if('A'<=a&&a<='C'&&'A'<=b&&b<='C')return 1;
	else if('D'<=a&&a<='E'&&'D'<=b&&b<='E')return 1;
	else return 0;
}
bool pd2(char a,char b){
	if(a>b)swap(a,b);
	if(a+1==b){
		if(a=='C')return 0;
		else return 1;
	}
	else return 0;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r_csh>>r_zwh>>x_csh>>x_zwh;
	r_p=turn_number(r_zwh);
	x_p=turn_number(x_zwh);
	if(r_csh==x_csh)cout<<1;
	else cout<<0;
	if(r_csh==x_csh&&r_p==x_p)cout<<1;
	else cout<<0;
	if(r_csh==x_csh&&r_p==x_p&&pd1(r_zwh[2],x_zwh[2]))cout<<1;
	else cout<<0;
	if(r_csh==x_csh&&r_p==x_p&&pd1(r_zwh[2],x_zwh[2])&&pd2(r_zwh[2],x_zwh[2]))cout<<1;
	else cout<<0;
	return 0;
}
