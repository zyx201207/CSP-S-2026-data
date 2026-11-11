#include<bits/stdc++.h>
using namespace std;
long long a,b,c[5];
char s1[3],s2[3];
int main(){
	cin>>a>>s1[0]>>s1[1]>>s1[2]>>b>>s2[0]>>s2[1]>>s2[2];
	freopen("travel.in","r",stdin);
	if(a==b){
		c[0] = 1;
		if(s1[0]==s2[0] && s1[1]==s2[1]){
			c[1] = 1;
			if(s1[2]<='C'&&s2[2]<='C' || s1[2]>'C'&&s2[2]>'C'){
				c[2] = 1;
				if(s1[2]+1==s2[2] || s1[2]-1==s2[2]){
					c[3] = 1;
				}
			}
		}
	}
	for(int i=0;i<4;i++)
		printf("%lld",c[i]);
	freopen("travel.out","w",stdout);
	return 0;
}
