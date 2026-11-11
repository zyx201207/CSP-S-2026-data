#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<'1';
	else{
	    printf("%c",'0000');
	    return 0;
	}
	string a1,a2; 
	for(int i=0;i<3;i++){
		if(s1[i]>='A'&&s1[i]<='F') a1=s1[i];
		if(s2[i]>='A'&&s2[i]<='F') a2=s2[i];
	}
	string b1,b2;
	b1=s1[0]+s1[1];
	b2=s2[0]+s2[1]; 
	if(b1==b2) cout<<'1';
	else{
		printf("%c",'000');
		return 0;
	}
	int q1=0,q2=0;
	if(a1=="D"||a1=="F") q1=1;
	if(a2=="D"||a2=="F") q2=1;
	if(q1==q2) cout<<'1';
	else{
		printf("%c%c",'0','0');
		return 0; 
	}
	if(a1=="D"||a1=="F"){
		if(a2!="D"&&a2!="F"){
			cout<<"0"; 
		}
		else cout<<1;
	}
	else {
		if(a2=="D"||a2=="F"){
			cout<<"0"; 
		}
		else cout<<1;
	}
	return 0;
} 
