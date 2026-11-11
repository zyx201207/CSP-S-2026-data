#include<bits/stdc++.h>
#define int long long
using namespace std;
bool aaa(char x,char l,char r){
	return (x>=l&&x<=r);
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	char s1,s2;
	string st1,sr1,st2,sr2;
	cin>>st1>>sr1>>st2>>sr2;
	s1=sr1[2];s2=sr2[2];
	sr1[2]=0;sr2[2]=0;
	if(s1=='F')
		s1='E';
	if(s2=='F')
		s2='E';
	if(st1==st2){
		cout<<'1';
		if(sr1==sr2){
			cout<<'1';
			if((aaa(s1,'A','C')&&aaa(s2,'A','C'))||(aaa(s1,'D','E')&&aaa(s2,'D','E'))){
				cout<<'1';
				if(s1+1==s2||s1-1==s2)
					cout<<'1';
				else
					cout<<'0';
			}else
				cout<<"00";
		}else
			cout<<"000";
	}else
		cout<<"0000";
	return 0;
}

