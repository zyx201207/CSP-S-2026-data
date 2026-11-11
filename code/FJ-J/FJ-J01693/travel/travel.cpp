#include<bits/stdc++.h>
using namespace std;
char xiang1[3],xiang2[3],wei1[4],wei2[4];
int a[5]={0,1,1,1,1};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%s%s%s%s",xiang1+1,wei1+1,xiang2+1,wei2+1);
	for(int i=1;i<=2;i++){
		if(xiang1[i]!=xiang2[i]){
			a[1]=0;
			a[2]=0;
			a[3]=0;
			a[4]=0;
			for(int i=1;i<=4;i++){
				printf("%d",a[i]);
			}
			return 0;
		}
	}
	for(int i=1;i<=2;i++){
		if(wei1[i]!=wei2[i]){
			a[2]=0;
			break;
		}
	}
	if(a[2]){
		if(wei1[3]-'A'<3&&wei2[3]-'A'<3){
			a[3]=1;
			if(wei1[3]=='C'&&wei2[3]=='A'||wei2[3]=='C'&&wei1[3]=='A'){
				a[4]=0;
			}
		}
		else if(wei1[3]-'A'>=3&&wei2[3]-'A'>=3){
			a[3]=1;
			a[4]=1;
		}
		else {
			a[3]=0;
			a[4]=0;
		}
	}
	else{
		a[3]=0;
		a[4]=0;
	}
	for(int i=1;i<=4;i++){
		printf("%d",a[i]);
	}
	return 0;
}
