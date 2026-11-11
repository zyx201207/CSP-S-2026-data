#include <bits/stdc++.h>
using namespace std;
bool side(string a,string b){
	int s1,s2;
	if(a[2]=='A'||a[2]=='B'||a[2]=='C') s1=1;
	else s1=0;
	if(b[2]=='A'||b[2]=='B'||b[2]=='C') s2=1;
	else s2=0;
	return s2==s1;
}
bool on_side(string a,string b){
	if(((a[2]=='A')&&(b[2]=='B'))||((a[2]=='B')&&(b[2]=='A'))) return true;
	else if((a[2]=='B')&&(b[2]=='C')||(a[2]=='C')&&(b[2]=='B')) return true;
	else if((a[2]=='E')&&(b[2]=='D')||(a[2]=='D')&&(b[2]=='E')) return true ;
	return false;
}
int turn (string d){
	int a=0;
	for (int i=0;i<d.size();i++){
		a=a*10+d[i]-'0';
	}
	return a;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a[10];
	for (int i=1;i<=4;i++){
		scanf("%s",&a[i]);
	}
	if(a[1]!=a[3]) printf("%s","0000");
	else if(turn(a[2].substr(0,2))!=turn(a[4].substr(0,2))) printf("%s","1000");
	else if(!side(a[2],a[4])) printf("%s","1100");
	else if(!on_side(a[2],a[4])) printf("%s","1110");
	else printf("%s","1111");
	return 0;
} 
