#include <bits/stdc++.h>
std::string c1,s1,c2,s2;
char ans[4];
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	std::cin>>c1>>s1>>c2>>s2;
	if(c1==c2) {
		ans[0]='1';
		if(s1[0]==s2[0]&&s1[1]==s2[1]) {
			ans[1]='1';
			if((s1[2]<'D'&&s2[2]<'D')||(s1[2]>'C'&&s2[2]>'C')) {
				ans[2]='1';
				if(std::abs(int(s1[2]-s2[2]))==1) ans[3]='1';
				else ans[3]='0';
			} else {
				ans[2]=ans[3]='0';
			}
		} else {
			ans[1]=ans[2]=ans[3]='0';
		}
	} else {
		ans[0]=ans[1]=ans[2]=ans[3]='0';
	}
	for(int i=0;i<4;i++) std::cout<<ans[i];
	return 0;
} 
