#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	bool a,b,c,d;
	a=b=c=d=0;
	if(c1==c2){
		a=1;
		if(s1[1]==s2[1]){
			b=1;
			if('A'<=s1[2]&&s1[2]<='C'&&'A'<=s2[2]&&s2[2]<='C'){
				c=1;
			}
			if('D'<=s1[2]&&s1[2]<='F'&&'D'<=s2[2]&&s2[2]<='F'){
				c=1;
			}
		}
	}
	for(int i=-1;i<=1;i+=2){
		if(s1[2]+i==s2[2]&&c)	d=1;
	}
	cout<<a<<b<<c<<d;
	
	return 0;
}
