#include<bits/stdc++.h>
using namespace std;
int a,b;
string s1,s2;
int main(){
	cin>>a>>s1>>b>>s2;
	int num1=(s1[0]-'0')*10+(s1[1]-'0');
	int num2=(s2[0]-'0')*10+(s2[1]-'0');
	char st1=s1[2],st2=s2[2];
	if(a==b){
		cout<<1;
		if(num1==num2){
			cout<<1;
			if(((st1=='D' || st1=='F')&&(st2=='D' || st2=='F')&& st1!=st2) || ((st1=='A' || st1=='B' || st1=='C')&&(st2=='A' || st2=='B' || st2=='C')&& st1!=st2)){
				cout<<1;
				if(((st1=='D' || st1=='F')&&(st2=='D' || st2=='F')&& st1!=st2) || (st1=='A' && st2=='B') || (st1=='B' && (st2=='A' || st2=='C')) || (st1=='c' && st2=='B')){
					cout<<1;
				}
				else{
					cout<<0;
					return 0;
				}
			}
			else{
				cout<<"00";
				return 0;
			}
		}
		else{
			cout<<"000";
			return 0;
		}
	}
	else {
		cout<<"0000";
		return 0;
	}
	
	return 0;
} 
