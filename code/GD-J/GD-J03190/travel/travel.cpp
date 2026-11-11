#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5+10,inf=1e15,md=1e9+7;
char a,b,c;
ll read(){
	ll ans=0,f=1;
	char s=' ';
	while(!(s>='0'&&s<='9')){
		s=getchar();
		if(s=='-')f=-1;
	}
	while(s>='0'&&s<='9'){
		ans=ans*10+s-'0';
		s=getchar();
	}
	if(s>='A'&&s<='F')c=s;
	return ans*f;
}
ll c1,c2,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	c1=read();s1=read();a=c;
	c2=read();s2=read();b=c;
	if(c1!=c2){
		printf("0000");
		return 0;
	}
	putchar('1');
	if(s1!=s2){
		printf("000");
		return 0;
	}
	putchar('1');
	if(a>b)swap(a,b);
	if(a<='C'&&b>='D'){
		printf("00");
		return 0;
	}
	putchar('1');
	if(b-a==1)putchar('1');
	else putchar('0');
	return 0;
}

