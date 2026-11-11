#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2&&c1!="01"&&c1!="16"&&c2!="01"&&c2!="16"){
		printf("%s","1");
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			printf("%s","1");
			int a=int(s2[2])-int(s1[2]);
			if((s1[2]=='A'&&a<=2)||(s1[2]=='B'&&a<=1)||(s1[2]=='C'&&a<=-1)||(s1[2]=='D'&&a==1)||(s1[2]=='F'&&a==-1)){
				printf("%s","1");
				if(abs(int(s1[2])-int(s2[2]))==1)printf("%s","1");
				else printf("%s","0");
			}
			else printf("%s","00");
		}
		else printf("%s","000");
	}
	else printf("%s","0000");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
