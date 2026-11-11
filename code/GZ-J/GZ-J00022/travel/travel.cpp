//GZ-J00022,商梓辰，贵阳市第三中学
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	ll flag=1;
	if(c1==c2) cout<<1;
	else{
		cout<<0;
		flag=0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&flag) cout<<1;
	else{
		cout<<0;
		flag=0;
	}
	if(((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C'))&&flag){
		cout<<1;
		 
	}else{
		cout<<0;
		flag=0;
	}
	if(abs(s1[2]-s2[2])==1&&flag) cout<<1;
	else cout<<0; 
	return 0;
	 
} 
