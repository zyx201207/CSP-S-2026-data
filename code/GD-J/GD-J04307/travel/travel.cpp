#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<1;
	else cout<<0;
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]) cout<<1;
	else cout<<0;
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]){
		if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C') cout<<1;
		else if(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F') cout<<1;
		else cout<<0;
	}
	else cout<<0;
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]){
		int x1=(int)(s1[2]),x2=(int)(s2[2]);
		if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C'){
			if(x1-x2==1||x1-x2==-1) cout<<1;
			else cout<<0;
		}
		else if(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F'){
			if(x1-x2==1||x1-x2==-1) cout<<1;
			else cout<<0;
		}
		else cout<<0;
	}
	else cout<<0;
} 
