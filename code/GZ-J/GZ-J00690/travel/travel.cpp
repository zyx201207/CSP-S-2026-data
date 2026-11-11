//GZ-J00690   öÄ²Åº­ 
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string a;
	getline(cin,a);
	
	int len=a.size();
	
	if((a[0]-'0')*10+(a[1]-'0')==((a[7]-'0')*10+(a[8]-'0'))){
		printf("1");
	}else{
		printf("0");
	}

	if((a[0]-'0')*10+(a[1]-'0')==((a[7]-'0')*10+(a[8]-'0'))){
			if((a[3]-'0')*10+(a[4]-'0')==((a[10]-'0')*10+(a[11]-'0'))){
		printf("1");
	}else{
		printf("0");
	}
	}else{
		printf("0");
	}
	
	if((a[0]-'0')*10+(a[1]-'0')==((a[7]-'0')*10+(a[8]-'0'))){
		if((a[3]-'0')*10+(a[4]-'0')==((a[10]-'0')*10+(a[11]-'0'))){
			if(a[5]=='A'||a[5]=='B'||a[5]=='C'){
				if(a[12]=='A'||a[12]=='B'||a[12]=='C'){
					printf("1");
				}else{
					printf("0");
				}
		}else if(a[5]=='D'||a[5]=='F'){
			if(a[12]=='D'||a[12]=='F'){
				printf("1");
			}else{
				printf("0");
			}
		}
		}else{
			printf("0");
		}
	}else{
		printf("0");
	}
	
	if((a[3]-'0')*10+(a[4]-'0')==((a[10]-'0')*10+(a[11]-'0'))){
			if(a[5]>='A'&&a[5]<='C'&&a[12]>='A'&&a[12]<='C'){
				if(abs(a[5]-a[12])==1){
					printf("1");
				}else{
					printf("0");
				}
			}else if(a[5]>='D'&&a[5]<='F'&&a[12]>='D'&&a[12]<='F'){
				printf("1");
			}else{
				printf("0");
			}
	}else{
		printf("0");
	}

	fclose(stdin);
	fclose(stdout);

	return 0;

}

