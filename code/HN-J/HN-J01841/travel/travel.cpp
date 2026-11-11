#include<bits/stdc++.h>
using namespace std;
int a1,a3,b1,b3;
char a2,b2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf(" %d %d %c",&a1,&a3,&a2);
	scanf(" %d %d %c",&b1,&b3,&b2);
	if(a1==b1) printf("%d",1);
	else
	{
		cout<<"0000";
		return 0;
	} 
	
	if(a3==b3) printf("%d",1);
	else
	{
		cout<<"000";
		return 0;
	} 
	int y=a2-'A'+1;
	int z=b2-'A'+1;
	if((y<=3&&z<=3)||(y>3&&z>3)) printf("%d",1);
	else
	{
		cout<<"00";
		return 0;
	}
	if(y-z==1||y-z==-1) printf("%d",1);
	else
	{
		printf("%d",0);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
