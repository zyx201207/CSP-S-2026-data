#include<iostream> 
#include<string> 
#include<cstdio> 
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,c1,c2;
	int a,b,c,d;
	cin>>s1>>c1>>s2>>c2;
	if(s1!=s2){
		a=b=c=d=0;
	}else{
		a=1;
		if(c1[0]==c2[0]&&c1[1]==c2[1]){
			b=1;
			char t1=c1[2],t2=c2[2];
			if(t1>t2)swap(t1,t2);
			if(t1=='A'&&t2=='B'||t1=='A'&&t2=='C'||t1=='B'&&t2=='C'||t1=='D'&&t2=='E'){
				c=1;
				if(t1=='A'&&t2=='B'||t1=='B'&&t2=='C'||t1=='D'&&t2=='E'){
					d=1;
				}else d=0;
			}else{
				c=d=0;
			}
		}else{
			b=c=d=0;
		}
	}
	cout<<a<<b<<c<<d;
	return 0;
}
