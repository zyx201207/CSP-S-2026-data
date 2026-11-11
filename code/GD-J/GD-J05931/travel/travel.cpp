#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		printf("0000");
	}else{
		printf("1");
		if(s1[0]!=s2[0]||s1[1]!=s2[1])
			printf("000");
		else{
			printf("1");
			int a=(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'),
				b=(s2[2]=='A'||s2[2]=='B'||s2[2]=='C');
			if(a!=b)
				printf("00");
			else{
				printf("1");
				if(s1[2]+1==s2[2]||s1[2]-1==s2[2])
					printf("1");
				else printf("0");
			}
		}
	}
	
	return 0;
}
