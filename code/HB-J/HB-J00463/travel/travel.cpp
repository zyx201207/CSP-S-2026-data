#include<bits/stdc++.h>
using namespace std;
char a[5][5];
bool s[5]={1,1,1,1};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=0;i<4;i++)
		cin>>a[i];
	if(strcmp(a[0],a[2])!=0) s[0]=0;
	if(!s[0]||strncmp(a[1],a[3],2)!=0) s[1]=0;
	char maxc=max(a[1][2],a[3][2]),minc=min(a[1][2],a[3][2]);
	if(!s[0]||!s[1]||maxc=='D'||(maxc=='F'&&minc<='C')) s[2]=0;
	if(!s[0]||!s[1]||!s[2]||(maxc-minc!=1&&maxc!='F')) s[3]=0;
	for(int i=0;i<4;i++) cout<<s[i];
	return 0;
}
