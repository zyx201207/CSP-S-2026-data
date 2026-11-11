#include<iostream>
#include<cstdio>
using namespace std;
int t1,t2;
int a1,a2;
char c1,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	scanf("%d %d%c %d %d%c",&t1,&a1,&c1,&t2,&a2,&c2);
	if(t1!=t2){cout<<"0000";return 0;}
	if(a1!=a2){cout<<"1000";return 0;}
	int b1=(c1>='A' && c1<='C') ? 0 : 1,b2=(c2>='A' && c2<='C') ? 0 : 1;
	if(b1!=b2){cout<<"1100";return 0;}
	int d1=c1-'A',d2=c2-'A';
	if(( d1+1==d2 || d1-1==d2 ) && ( (c1!='C' && c2!='D') || (c1!='D' && c2!='C') ))
		cout<<"1111";
	else	cout<<"1110";
	return 0;
}
