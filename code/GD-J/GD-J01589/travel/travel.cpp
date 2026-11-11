#include<bits/stdc++.h>

typedef long long LL;
typedef unsigned long long ULL;

#define mkp make_pair
#define PII pair<int,int>

using namespace std;

const int L=12;

char c1[L],s1[L],c2[L],s2[L];

bool ans[10];
int getnum(char ch){
	return ch-'0';
}
int x,y,p1,p2,z1,z2;

int main(){
	freopen("travel.in","r",stdin);
	// freopen("travel5.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	scanf("%s %s %s %s",c1,s1,c2,s2);
	if(s1[2]=='F') s1[2]='E';
	if(s2[2]=='F') s2[2]='E';
	x=getnum(c1[0]),y=getnum(c1[1]);
	p1=x*10+y;
	x=getnum(c2[0]),y=getnum(c2[1]);
	p2=x*10+y;
	ans[1]=(p1==p2);
	
	x=getnum(s1[0]),y=getnum(s1[1]);
	z1=x*10+y;
	x=getnum(s2[0]),y=getnum(s2[1]);
	z2=x*10+y;
	ans[2]=((ans[1]) && (z1==z2));
	
	ans[3]=((ans[2]) && (((s1[2]>='D') && (s2[2]>='D')) || (s1[2]<='C' && s2[2]<='C')));
	
	// cout<<getnum(s1[2])<<" "<<getnum(s2[2])<<"\n";
	ans[4]=((ans[3]) && (int(abs(int(s1[2]-s2[2])))<=1));
	
	for(int i=1;i<=4;i++){
		printf("%d",((ans[i])?1:0));
	}putchar('\n');
	return 0;
}
