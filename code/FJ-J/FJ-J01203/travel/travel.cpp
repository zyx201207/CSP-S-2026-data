#include<bits/stdc++.h>
#include<string>
using namespace std;
string c1,s1,c2,s2;
char a[4] = {'0','A','B','C'};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1 != c2){
		printf("0000\n");
	}else{
		if(s1[0]+s1[1] != s2[0]+s2[1]){
			printf("1000\n");
		}else{
			bool v1 = 0,v2 = 0;
			for(int i = 1;i<=3;i++){
				if(s1[2] == a[i]) v1 = 1;
				else if(s2[2] == a[i]) v2 = 1;
			}
			if(v1 == v2){
				if(abs(s1[2]-s2[2]) == 1 && ((s1[2] != 'C' && s2[2] != 'D') || (s1[2] != 'D' && s2[2] != 'C'))){
					printf("1111");
				}else{
					printf("1110");
				}
			}else{
				printf("1100");	
			}
		}
	}
	return 0;
}
