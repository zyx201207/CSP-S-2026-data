#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool check(int x,int y){
	if((x==68&&y==69)||(x==68&&y==69))
		return true;
 if(x==68||x==69||y==68||y==69)
		return false;
	else return true;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int num1=10*(s1[0]-'0')+(s1[1]-'0');
	int word1=s1[2];
	int num2=10*(s2[0]-'0')+(s2[1]-'0');
	int word2=s2[2];
	if(c1==c2) printf("1");
    else printf("0");
	if(c1==c2&&num1==num2) printf("1");
	else printf("0");
	if(c1==c2&&num1==num2&&check(word1,word2))
		printf("1");
	else printf("0");
	if((abs(num1-num2)==1&&word1==word2)||(abs(word1-word2)==1&&num1==num2&&check(word1,word2)))
		printf("1");
	else printf("0");
	return 0;
} 

