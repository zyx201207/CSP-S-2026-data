#include <bits/stdc++.h>
using namespace std;
string c1,s1,s2,c2;
int ans[4];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>> c1 >> s1 >> c2 >> s2;
	if(c1==c2)ans[0]=1;
	if(s1[0]==s2[0]&&s1[1]==s2[1])ans[1]=1;
	char a=s1[2],b=s2[2];
	if(a>='A'&&a<='C'&&b>='A'&&b<='C')ans[2]=1;
	if(a>='D'&&a<='F'&&b>='D'&&b<='F')ans[2]=1;
	if(abs(a-b)==1)ans[3]=1;
	printf("%d%d%d%d",ans[0],ans[1],ans[2],ans[3]);
	return 0;
}

