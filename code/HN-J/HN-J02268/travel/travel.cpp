#include<bits/stdc++.h>
#define ll long long
using namespace std;
int s1,s2,g1,g2;
char c1,c2;
int main(){
//	freopen("travel.in","r",stdin);
//	freopen("travel.out","w",stdout);
	cin>>s1>>g1>>c1>>s2>>g2>>c2;
	if(s1==16)	s1=1;
	if(s2==16)	s2=1;
	if(s1==s2){
		cout<<1;
		if(g1==g2){
			cout<<1;
			if(c1<'D'&&c2<'D'){
				cout<<1;
				if(abs(c1-c2)==1&&max(c1,c2)!='D'&&min(c1,c2)!='C')	cout<<1;
				else	cout<<0;
			}	
			else if(c1>'C'&&c2>'C'){
				cout<<1;
				if(abs(c1-c2)==1&&max(c1,c2)!='D'&&min(c1,c2)!='C')	cout<<1;
				else	cout<<0;
			}	
			else	cout<<0<<0;
			
		}
		else	cout<<0<<0<<0;
	}	
	else	cout<<0<<0<<0<<0;
	
	return 0;
}
