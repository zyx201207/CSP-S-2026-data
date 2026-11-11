#include <bits/stdc++.h>
using namespace std;
string  s1,s2;
int c1,c2,ans=1;
int a[5];

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<4;i++){
		a[i]=0;
		if(i==0){
			if(c1==c2){a[i]=1;}
			}
		if(i!=0){
			if(a[i-1]==0){a[i]=0;cout<<a[i];continue;}
			if(i==1 && s1[i-1]==s2[i-1] && s1[i]==s2[i]){a[i]=1;}
			if(i==2  ){if(s1[2]==68 || s1[2]==70){if(s2[2]==68||s2[2]==70){a[2]=1;}}}
			else{if(s2[2]!=68||s2[2]!=70){a[2]=1;}}
			if(i==3){if(s1[2]-1==s2[2]||s1[2]+1==s2[2]){a[3]=1;}
				}}
		cout<<a[i];
		}
	return 0;}
