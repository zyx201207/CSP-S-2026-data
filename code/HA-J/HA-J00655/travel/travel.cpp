#include <bits/stdc++.h>
#define ll long long

using namespace std;
//const int N=
char c1[10],s1[10],c2[10],s2[10];
bool r=1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0]&&c1[1]==c2[1])printf("1");
	else{
		printf("0");
		r=0;	
	}
	if(r&&s1[0]==s2[0]&&s1[1]==s2[1])printf("1");
	else{
		printf("0");
		r=0;
	}
	if(r&&s1[0]==s2[0]&&s1[1]==s2[1]){
		if(r&&((s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')||(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F'))){
			printf("1");
		}else{
			printf("0");
			r=0;
		}
	}else{
		printf("0");
		r=0;
	}
	int a=s1[2]-'A',b=s2[2]-'A';
	if(r&&abs(a-b)==1){
		printf("1");
	}else printf("0");
	return 0;
}
