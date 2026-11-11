#include <bits/stdc++.h>
#define endl putchar('\n')
#define lowbit(x) ((x)&(-(x)))
using namespace std;
int read(){
	char c=getchar();
	int x=0;bool flag=false;
	while(c>'9' || c<'0'){
		if(c=='-') flag=true;
		c=getchar();
	}
	while(c<='9' && c>='0'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return flag ? -x : x;
}
string reads(){
	char c=getchar();
	string s="";
	while((c>'9' || c<'0') && (c>'Z' || c<'A')) c=getchar();
	while((c<='9' && c>='0') || (c<='Z' && c>='A')){
		s+=c;
		c=getchar();
	}
	return s;
}
void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1=reads(), s1=reads(), c2=reads(), s2=reads();
	if(c1==c2){
		putchar('1');
		if(s1.substr(0,2)==s2.substr(0,2)){
			putchar('1');
			if(s1[2]<='C' && s2[2]<='C' || s1[2]>'C' && s2[2]>'C'){
				putchar('1');
				if(abs(s1[2]-s2[2])==1){
					putchar('1');
				}
				else{
					putchar('0');
				}
			}
			else{
				putchar('0');
				putchar('0');
			}
		}
		else{
			putchar('0');
			putchar('0');
			putchar('0');
		}
	}
	else{
		putchar('0');
		putchar('0');
		putchar('0');
		putchar('0');
	}
	return 0;
}
