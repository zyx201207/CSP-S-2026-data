#include<bits/stdc++.h>
using namespace std;
int c1,c2,s1,s2;
char t1,t2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char c;
	cin>>c1;
	cin>>c;
	s1=(c-'0')*10;
	cin>>c;
	s1+=c-'0';
	cin>>c;
	t1=c;
	cin>>c2;
	cin>>c;
	s2=(c-'0')*10;
	cin>>c;
	s2+=c-'0';
	cin>>c;
	t2=c;
	cout<<(c1==c2);
	cout<<((c1==c2)&&(s1==s2));
	cout<<((c1==c2)&&(s1==s2)&&((t1<='C'&&t2<='C')||(t1>='D'&&t2>='D')));
	cout<<((c1==c2)&&(s1==s2)&&((t1=='A'&&t2=='B')||(t1=='B'&&(t2=='A'||t2=='C'))||(t1=='C'&&t2=='B')||(t1=='D'&&t2=='F')||(t1=='F'&&t2=='D')));
	return 0;
} 
