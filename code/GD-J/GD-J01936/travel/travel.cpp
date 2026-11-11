#include<bits/stdc++.h>
using namespace std;

string s1,s2;
int a,b;

int f(string s){
	return (s[0]-'0')*10+s[1]-'0';
}
int g(string s){
	return s[2]-'A'+1;
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>s1>>b>>s2;
	if(a==b){
		cout<<1;
		if(f(s1)==f(s2)){
			cout<<1;
			if(g(s1)<=3 && g(s2)<=3){
				cout<<1;
				if(abs(g(s1)-g(s2))<=1){
					cout<<1;
				}else{
					cout<<0;
				}
			}
			else if(g(s1)>=4 && g(s2)>=4){
				cout<<1;
				if(abs(g(s1)-g(s2))==2){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<"00";
			}
		}else
			cout<<"000";
	}
	else
		cout<<"0000";
	return 0;
} 
