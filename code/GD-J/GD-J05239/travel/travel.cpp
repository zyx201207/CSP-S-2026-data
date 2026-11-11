#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int che1,che2,zuo1,zuo2;
	char a,b;
	scanf("%d%d%c%d%d%c",&che1,&zuo1,&a,&che2,&zuo2,&b);
	if(che1==che2) printf("1");
	else{
		printf("0000");
		return 0;
	}
	if(zuo1==zuo2) printf("1");
	else{
		printf("000");
		return 0;
	}
	if((a=='D'&&b=='F')||(a=='F'&&b=='D')||(a!='F'&&b!='D'&&a!='D'&&b!='F')) printf("1");
	else{
		printf("00");
		return 0;
	}
	if(a=='F'||a=='D'||abs(int(a-b))==1) printf("1");
	else printf("0");
	return 0;
} 
