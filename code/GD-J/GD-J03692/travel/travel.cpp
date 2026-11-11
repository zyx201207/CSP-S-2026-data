#include<bits/stdc++.h>
using namespace std;
int t;
int rd(){
	int x=0;
	char ch=getchar();
	while((ch<'0'||ch>'9')&&(ch<'A'||ch>'Z')) ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	if(ch>='A'&&ch<='Z')t=ch-'A',ch=getchar();
	return x;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a=rd(),b=rd(),c=t,d=rd(),e=rd(),f=t;
	if(c==5)c--;
	if(f==5)f--;
	int flag=1;
	if(a!=d)flag=0;
	putchar(flag+'0');
	if(b!=e)flag=0;
	putchar(flag+'0');
	if((c<=2&&f>2)||(c>2&&f<=2))flag=0;
	putchar(flag+'0');
	if(abs(c-f)!=1)flag=0;
	putchar(flag+'0');
	return 0;
} 
/*
03 01D 03 01F
*/
