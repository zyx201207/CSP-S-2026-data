#include<bits/stdc++.h>
using namespace std;
string s1,s2,s;
int a,b,aa,bb;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s;
	a=(s[0]-'0')*10+s[1]-'0';
	cin>>s1;
	cin>>s;
	b=(s[0]-'0')*10+s[1]-'0';
	cin>>s2;
	if(a==b){
		cout<<1;
		a=(s1[0]-'0')*10+s1[1]-'0';
		b=(s2[0]-'0')*10+s2[1]-'0';
		if(a==b){
			cout<<1;
			if(s1[2]>='A'&&s1[2]<='C')
				a=1;
			else
				a=2;
			if(s2[2]>='A'&&s2[2]<='C')
				b=1;
			else
				b=2;
			if(a==b){
				cout<<1;
				if(abs(s1[2]-s2[2])==1)
					cout<<1;
				else
					cout<<0;				
			}
			else
				cout<<"00";
		}
		else{
			cout<<"000";
		}
	}
	else
		cout<<"0000";
	return 0;
}
