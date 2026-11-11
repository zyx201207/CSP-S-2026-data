#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int ss1=char(s1[0]-48)*10+char(s1[1]-48);
	int ss2=char(s2[0]-48)*10+char(s2[1]-48);
	if(c1==c2){
		cout<<1;
		if(ss1==ss2){
			cout<<1;
			if(s1[2]-65<3&&s2[2]-65<3||s1[2]-65>=3&&s2[2]-65>=3){
				cout<<1;
				if(s1[2]-64-(s2[2]-64)==1||s1[2]-64-(s2[2]-64)==-1){
					cout<<1;
				}else cout<<0;
			}else cout<<0<<0;
		}else cout<<0<<0<<0;
	}else cout<<0<<0<<0<<0;		
}
       