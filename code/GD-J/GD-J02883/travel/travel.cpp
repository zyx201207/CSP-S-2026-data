#include<bits/stdc++.h>
using namespace std;
int main(){
#ifndef DEBUG_
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
#endif
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		putchar('1');
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			putchar('1');
			if(('A'<=s1[2]&&s1[2]<='C'&&'A'<=s2[2]&&s2[2]<='C')||('D'<=s1[2]&&s1[2]<='F'&&'D'<=s2[2]&&s2[2]<='F')){
				putchar('1');
				if((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')||(((s1[2]-s2[2]==1)||s1[2]-s2[2]==-1)&&s1[2]!='D'&&s2[2]!='D'))
					putchar('1');
				else
					putchar('0');
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
