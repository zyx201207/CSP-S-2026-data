#include<bits/stdc++.h>
#include<conio.h>
#include<iostream>
using namespace std;
char a[5],b[5],c[5],d[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a1 = 1,a2 = 1,a3 = 1,a4 = 1;
	scanf("%s",a + 1);
	scanf("%s",b + 1);
	scanf("%s",c + 1);
	scanf("%s",d + 1);
	for(int i = 1;i <= 5;i++){
		if(a[i] != c[i]){
			a1 = 0;
			a2 = 0;
			a3 = 0;
			a4 = 0;
			printf("%d%d%d%d",a1,a2,a3,a4);
			return 0;
		}
	}
	int k1 = 0,k2 = 0;
	for(int i = 1;i <= 5;i++){
		if(b[i] - '0' >= 9){
			break;
		}
		k1 += 1;
	}
	for(int i = 1;i <= 5;i++){
		if(d[i] - '0' >= 9){
			break;
		}
		k2 += 1;
	}
	if(k1 != k2){
		a2 = 0;
		a3 = 0;
		a4 = 0;
		printf("%d%d%d%d",a1,a2,a3,a4);
		return 0;
	}
	for(int i = 1;i <= k1;i++){
		if(b[i] != d[i]){
			a2 = 0;
			a3 = 0;
			a4 = 0;
			printf("%d%d%d%d",a1,a2,a3,a4);
			return 0;
		}
	}
	if((b[k1 + 1] >= 'D' && d[k2 + 1] <= 'C')||(b[k1 + 1] <= 'C' && d[k2 + 1] >= 'D')){
		a3 = 0;
		a4 = 0;
		printf("%d%d%d%d",a1,a2,a3,a4);
		return 0;
	}
	if((b[k1 + 1] == 'C'&&d[k2 + 1] == 'A')||(b[k1 + 1] == 'A'&&d[k2 + 1] == 'C')){
		a4 = 0;
		printf("%d%d%d%d",a1,a2,a3,a4);
		return 0;
	}
	printf("%d%d%d%d",a1,a2,a3,a4);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
