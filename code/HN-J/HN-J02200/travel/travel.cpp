#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in.txt","r",stdin);
	freopen("travel.out.txt","w",stdout);
	string c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	char m=s1[2],n=s2[2];
	if(((c1[0]!=c2[0]) or (c1[1]!=c2[1]))){
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
	}
	else{
		cout<<1;
		if((s1[0]==s2[0]) and (s1[1]==s2[1])){
			cout<<1;
			if(((m-'C')>0 and (n-'C')>0) or ((m-'D')<0 and (n-'D')<0) or m==n){
				cout<<1;
			}
			else{
				cout<<0;
			}
		}
		if((s1[0]!=s2[0]) or (s1[1]!=s2[1])){
			cout<<0;
			cout<<0;
		}
		if((s1[0]==s2[0]) and (s1[1]==s2[1])){
			if((m=='C' and n=='D') or (m=='C' and n=='D') or abs(m-n)!=1){
				cout<<0;
			}
			else{
				cout<<1;
			}
			return 0;
		}
		if(m==n){
			if(abs((s1[0]*10+s1[1])-(s2[0]*10+s2[1]))==1){
				cout<<1;
			}
			else{
				cout<<0;
			}
			return 0;
		}
		if(m!=n and ((s1[0]!=s2[0]) or (s1[1]!=s2[1]))){
			cout<<0;
			return 0;
		}
	}	
}
