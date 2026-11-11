#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n1=0,n2=0,num1=0,num2=0;
	string s1,s2;
	cin>>n1>>s1>>n2>>s2;
	if(s1[2]==65||s1[2]==66||s1[2]==67) num1=1;
	if(s1[2]==68||s1[2]==70) num1=2;
	if(s2[2]==65||s2[2]==66||s2[2]==67) num2=1;
	if(s2[2]==68||s2[2]==70) num2=2; 
	if(n1==n2){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			if(num1==num2){
				cout<<1;
				if(s1[2]+1==s2[2]||s1[2]-1==s2[2]){
					cout<<1;
				}else cout<<0;
			}else cout<<0<<0;
		}else cout<<0<<0<<0;
	}else cout<<0<<0<<0<<0;
	return 0;
}
