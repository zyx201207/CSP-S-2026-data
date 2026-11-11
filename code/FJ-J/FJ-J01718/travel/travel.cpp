#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	long long x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return x*f;
}
//long long main+return 0
string c1,s1,c2,s2,p1,p2;
char cp1,cp2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	p1=s1.substr(2,1),p2=s2.substr(2,1);
	cp1=p1[0],cp2=p2[0];
	if(c1!=c2){
		printf("0000");
		return 0;
	}if(s1.substr(0,2)!=s2.substr(0,2)){
		printf("1000");
		return 0;
	}if(!(cp1=='A'&&cp2=='B'||
	cp1=='A'&&cp2=='C'||
	cp1=='B'&&cp2=='A'||
	cp1=='B'&&cp2=='C'||
	cp1=='C'&&cp2=='A'||
	cp1=='C'&&cp2=='B'||
	cp1=='D'&&cp2=='F'||
	cp1=='F'&&cp2=='D')){
		printf("1100");
		return 0;
	}if(!(cp1=='A'&&cp2=='B'||
	cp1=='B'&&cp2=='A'||
	cp1=='B'&&cp2=='C'||
	cp1=='C'&&cp2=='B'||
	cp1=='D'&&cp2=='F'||
	cp1=='F'&&cp2=='D')){
		printf("1110");
		return 0;
	}printf("1111");
	return 0;
}
