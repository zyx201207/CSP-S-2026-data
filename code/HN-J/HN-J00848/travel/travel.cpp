#include<bits/stdc++.h>
using namespace std;
char s1[4],s2[4],s3[4],s4[4]; 
char ans[5]={'0','0','0','0','0'};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%s%s%s%s",&s1,&s2,&s3,&s4);
//	printf("%c%c ",s1[0],s1[1]);
	if(s1[0]==s3[0]&&s1[1]==s3[1]){
		ans[1]='1';
		if(s2[0]==s4[0]&&s2[1]==s4[1]){
			ans[2]='1';
			if((s2[2]>='A'&&s2[2]<='C'&&s4[2]>='A'&&s4[2]<='C')||
			(s2[2]>='D'&&s2[2]<='F'&&s4[2]>='D'&&s4[2]<='F')){
				ans[3]='1';
				if(s2[2]-s4[2]==1||s2[2]-s4[2]==-1)ans[4]='1';
			}
		}
	}
	printf("%c%c%c%c",ans[1],ans[2],ans[3],ans[4]);
	return 0;
}
