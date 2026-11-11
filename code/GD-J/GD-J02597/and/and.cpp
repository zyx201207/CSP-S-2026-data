#include<bits/stdc++.h>
using namespace std;
int c1,s1,c2,s2;
int a[64];
int main(){
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)a[0]=1;
	else a[0]=0;
	if(s1==s2)a[1]=1;
	else a[1]=0;
	if(s2<='C'&&s1<='C'||s1>='D'&&s2>='D')a[2]=1;
	else a[2]=0;
	if(s1-s2==1||s2-s1==1)a[3]=1;
	else a[3]=0;
	for(int i=0;i<=3;i++){
		cout<<a[i];
	}
	
	return;
} 






