#include<iostream> 
#include<cstdio>
#include<string>
#include<cmath>
using namespace std;
bool yon(char c){
	return c<='C';
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,c1,s2,c2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		printf("1");
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			printf("1");
			if(yon(s1[2])==yon(s2[2])){
				printf("1");
				if(!yon(s1[2])||abs(s1[2]-s2[2])==1) printf("1");
				else printf("0");
			}
			else printf("00");
		}
		else printf("000");
	}
	else printf("0000");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
