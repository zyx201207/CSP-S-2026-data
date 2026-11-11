#include <bits/stdc++.h>
using namespace std;
char c1[5],s1[5],c2[5],s2[5];
int a[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%s%s%s%s",c1+1,s1+1,c2+1,s2+1);
	a[1]=a[2]=a[3]=a[4]=1;
	for(int i=1;i<=2;i++){
		if(c1[i]!=c2[i])a[1]=a[2]=a[3]=a[4]=0;
		if(s1[i]!=s2[i])a[2]=a[3]=a[4]=0;
	}
	if(s1[3]<'D'&&s2[3]>='D')a[3]=a[4]=0;
	if(s1[3]>='D'&&s2[3]<'D')a[3]=a[4]=0;
	else{
		if((s1[3]=='A'&&s2[3]=='C')||(s1[3]=='C'&&s2[3]=='A'))a[4]=0;
	}
	for(int i=1;i<=4;i++)cout<<a[i];
	return 0;
} 
