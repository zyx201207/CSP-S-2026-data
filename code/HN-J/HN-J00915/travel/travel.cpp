#include<bits/stdc++.h>
using namespace std;
char c1[10],s1[10],c2[10],s2[10];
int flag1=1,flag2=1,flag3=1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=1;i<=2;i++)cin>>c1[i];
	for(int i=1;i<=3;i++)cin>>s1[i];
	for(int i=1;i<=2;i++)cin>>c2[i];
	for(int i=1;i<=3;i++)cin>>s2[i];
	for(int i=1;i<=2;i++){
		if(c1[i]!=c2[i])flag1=0;
	}
	cout<<flag1;
	if(flag1==1){
		for(int i=1;i<=2;i++){
			if(s1[i]!=s2[i])flag2=0;
		}
    }else flag2=0;
	cout<<flag2;
	if(flag2==1&&flag1==1){
		if(s1[3]=='A'&&s2[3]=='D'||s2[3]=='C'&&s1[3]=='F')flag3=0;
		if(s1[3]=='A'&&s2[3]=='F'||s2[3]=='C'&&s1[3]=='F')flag3=0;
		if(s1[3]=='B'&&s2[3]=='D'||s2[3]=='C'&&s1[3]=='F')flag3=0;
		if(s1[3]=='B'&&s2[3]=='F'||s2[3]=='C'&&s1[3]=='F')flag3=0;
		if(s1[3]=='C'&&s2[3]=='D'||s2[3]=='C'&&s1[3]=='F')flag3=0;
		if(s1[3]=='C'&&s2[3]=='F'||s2[3]=='C'&&s1[3]=='F')flag3=0;
	}else flag3=0;
	cout<<flag3;
	if(flag1==1&&flag2==1&&flag3==1){
		if(s1[3]=='A'&&s2[3]=='B'||s2[3]=='B'&&s1[3]=='A')cout<<1;
		else if(s1[3]=='B'&&s2[3]=='C'||s2[3]=='C'&&s1[3]=='B')cout<<1;
		else if(s1[3]=='D'&&s2[3]=='F'||s2[3]=='F'&&s1[3]=='D')cout<<1;
		else cout<<0;
	}else{
		cout<<0;
	}
	return 0;
} 
