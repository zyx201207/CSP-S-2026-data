#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int c1,c2;
bool n,m,p,q;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		n=true;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			m=true;
			char x=s1[2],y=s2[2];
			if(((x>='D')&&(y>='D'))||((x<='C')&&(y<='C'))){
				p=true;
				if(abs(x-y)==1)q=true;
				}
			}
		}
	printf("%d%d%d%d",n,m,p,q);
	return 0;
}
