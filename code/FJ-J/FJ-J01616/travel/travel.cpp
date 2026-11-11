#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int c1,c2;
string s1,s2;
int a,b,c,d;
bool ans1=0,ans2=0,ans3=0,ans4=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>s1>>s2;
	a=s1[2]; 
	b=s2[2];
	c=s1[0]*10+s1[1];
	d=s2[0]*10+s2[1];
	cout<<a<<b;
	if(c1==c2){
		ans2=1;
		if(a<='C'&&b<='C'||a>'C'&&b>'C'){
			ans3=1;
			if(a-1==b||b-1==a){
				ans4=1;
			}
		}else if(a=='D'||a=='E'&&b=='D'||b=='E'){
			ans3=1;
			ans4=1;
		}
	}
	cout<<ans1<<ans2<<ans3<<ans4;
	return 0;
} 
