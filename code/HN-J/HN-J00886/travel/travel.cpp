#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,s1,c2,s2;
	char s11,s22;
	cin>>c1>>s1>>s11>>c2>>s2>>s22;
	if(c1==c2){
		cout<<1;
		if(s1==s2){
			cout<<1;
			if(s11>='A'&&s11<='C'){
				if(s22>='A'&&s22<='C'){
					cout<<1;
					if(s11==s22+1||s11+1==s22)
					cout<<1;
					else
					cout<<0;
				}
				else
				cout<<0<<0;
			}
			else{
				if(s22>='D'&&s22<='E'){
					cout<<1<<1;
				}
				else
				cout<<0<<0;
			}
		}
		else
		cout<<0<<0<<0;
	}
	else
	cout<<0<<0<<0<<0;
	return 0;
}
