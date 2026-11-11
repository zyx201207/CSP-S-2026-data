#include <bits/stdc++.h>
#include<cstdio>
using namespace std;
int a[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,c1,s2,c2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		a[0]=1;
		if(s1[1]==s2[1]){
			a[1]=1;
			if(('A'<=s1[2]&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')||('D'<=s1[2]&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F')){
				a[2]=1;
				if((s1[2]=='A'&&s2[2]=='B'||s1[2]=='B'&&s2[2]=='A')||(s1[2]=='B'&&s2[2]=='C'||s1[2]=='C'&&s2[2]=='B')||(s1[2]=='F'&&s2[2]=='D'||s1[2]=='D'&&s2[2]=='F')){
					a[3]=1;
				}
			}
		}
	}
	for(int i = 0;i<4;i++){
		cout<<a[i];
	}
	return 0;
}
