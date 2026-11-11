#include<bits/stdc++.h>
using namespace std;
int c1,c2,a,b;
char s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>a>>s1>>c2>>b>>s2;
	if(c1!=1&&c1!=16&&c2==c1){
		cout<<1;
		if(a==b){
			cout<<1;
			if((s1<='A'&&s1>='C'&&s2<='A'&&s2>='C')||(s1<='D'&&s1>='F'&&s2<='D'&&s2>='F')){
				cout<<1;
				if((s1<='A'&&s2>='B'&&s1!=s2)||(s1<='B'&&s2>='C'&&s1!=s2)||(s1<='D'&&s2>='F'&&s1!=s2)){
					cout<<1;
				}
				else{
					cout<<0;
					return 0;
				}
			}
			else{
				cout<<00;
				return 0;
			}
		}
		else {
			cout<<000;
			return 0;
		}
	}
	else {
		cout<<0000;
		return 0;
	}
	return 0;
} 

