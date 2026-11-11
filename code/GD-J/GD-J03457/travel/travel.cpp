#include<bits/stdc++.h>
using namespace std;
char c1[5],s1[5],c2[5],s2[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%s %s %s %s",c1,s1,c2,s2);
	bool f0=(c1[0]==c2[0]&&c1[1]==c2[1]);
	bool f1=((s1[0]==s2[0])&&(s1[1]==s2[1]));
	bool f2=((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')^(s2[2]=='D'||s2[2]=='F'));
	bool f3=((abs(int(s1[2]-s2[2])))==1);
	printf("%d",f0?1:0);
	printf("%d",(f0&&f1)?1:0);
	printf("%d",(f0&&f1&&f2)?1:0);
	printf("%d",(f0&&f1&&f2&&f3)?1:0);
	return 0;
}
