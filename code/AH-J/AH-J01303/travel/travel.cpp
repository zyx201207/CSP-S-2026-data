#include<bits/stdc++.h>
using namespace std;
int main(){
	int c1,c2,z1=0,z2=0;
	string s1,s2;
	char p1,p2;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	z1+=s1[0]-'0';
	z1*=10;
	z1+=s1[1]-'0';
	z2+=s2[0]-'0';
	z2*=10;
	z2+=s2[1]-'0';
	p1=s1[2];
	p2=s2[2];
	//c1,2 ³µÏáºÅ z1,2 ÅÆºÅ p1,2 ×ùÎ»×ÖÄ¸ 
	//cout<<c1<<' '<<z1<<' '<<p1<<' '<<c2<<' '<<z2<<' '<<p2<<endl;
	int t1=0,t2=0;
	if(c1==c2){
		cout<<1;
		t1=1;
	} 
	else {
		cout<<0;
	}
	if(t1==1&&z1==z2){
		cout<<1;
		t2=1;
	} 
	else {
		cout<<0;
	}	
	int cc=0,t3=0;
	if(p1=='A'&&p2=='B'||p1=='A'&&p2=='C'||p1=='B'&&p2=='C'||p1=='D'&&p2=='F'||p1=='F'&&p2=='D'||p1=='B'&&p2=='A'||p1=='C'&&p2=='A'||p1=='C'&&p2=='B')
	cc=1;
	if(t2==1&&cc==1){
		cout<<1;
		t3=1;
	} 
	else {
		cout<<0;
	}	
	int ccc=0;
	if(p1=='A'&&p2=='B'||p1=='B'&&p2=='C'||p1=='D'&&p2=='F'||p1=='F'&&p2=='D'||p1=='B'&&p2=='A'||p1=='C'&&p2=='B')
	ccc=1;
	if(t3==1&&ccc==1){
		cout<<1;
	} 
	else {
		cout<<0;
	}	
	return 0;
} 
