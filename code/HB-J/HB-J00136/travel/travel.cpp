#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		printf("0000");
	}
	else{
		printf("1");
		if(s1[0]!=s2[0]||s1[1]!=s2[1]){
			printf("000");
			//cout<<s1[0]<<s2[0]<<s1[1]<<s2[1];
		}
		else{
			printf("1");
			if(s1[2]<='C'&&s2[2]<='C'){
				printf("1");
				if(s1[2]!='B'&&s2[2]!='B'){
					printf("0");
				}
				else{
					printf("1");
				}
			}
			else if(s1[2]>='D'&&s2[2]>='D'){
				printf("11");
			}
			else{
				printf("00");
			}
		}
	}
	return 0;
}
