#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2,p1,p2;
	char s1,s2;
	cin>>c1>>p1>>s1>>c2>>p2>>s2;
	if(c1==c2){
		cout<<1;
		if(p1==p2){
			cout<<1;
			if(s1<='C'&&s2<='C'||s1>='D'&&s2>='D'){
				cout<<1;
				if(abs(s1-s2)==1){
					cout<<1;
				}else cout<<0;
			}else cout<<0<<0;
		}else cout<<0<<0<<0;
	}else cout<<0<<0<<0<<0;
	return 0;
} 
