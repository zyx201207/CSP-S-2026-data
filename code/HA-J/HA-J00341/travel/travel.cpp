#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int a=0;int b=0;int c=0;int d=0;
	if(c1==c2){
		a=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			b=1;
			if((s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')||(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F')){
				c=1;
				if((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')){
					d=1;
				}
				else if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')){
					d=1;
				}
				else if((s1[2]=='C'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')){
					d=1;
				}							
			}		
		}
		cout<<a<<b<<c<<d;
	}
	else{
		cout<<"0000";
	}
	return 0;
}
