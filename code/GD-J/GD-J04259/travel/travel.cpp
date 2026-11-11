#include<bits/stdc++.h>
using namespace std;
using ll=long long;
bool a,b,c,d;
char c1[3],c2[3],s1[4],s2[4];
char f1[3]={'A','B','C'},f2[2]={'D','F'};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%s%s%s%s",&c1,&s1,&c2,&s2);
	if(c1[0]==c2[0]&&c1[1]==c2[1]) a=1;
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&a) b=1;
	if(((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D'))&&b) c=1;
	if(((s1[2]>='D'&&s2[2]>='D')||(s1[2]<='B'&&s2[2]<='B')||((s1[2]>='B'&&s2[2]>='B')&&(s1[2]<='C'&&s2[2]<='C')))&&c) d=1;
	printf("%d%d%d%d\n",a,b,c,d);
	fclose(stdin);
	fclose(stdout);
	return 0;
}




































