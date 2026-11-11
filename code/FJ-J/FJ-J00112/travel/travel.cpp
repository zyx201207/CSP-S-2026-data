#include <bits/stdc++.h>
using namespace std;
int main()
{
	int u=0;
	string s1,s2;
	int c1,c2;
	cin>>c1>>s1>>c2>>s2;
	int ans[4];
	if(c1==c2){
		ans[0]=1;
		u=1;
	}
	else
		ans[0]=0;
	int islie=0;
	char a1,a2,a3,a4;
	a1=s1[0],a2=s2[0],a3=s1[1],a4=s2[1];
	if(a1==a2&&a3==a4){
		islie++;
		ans[1]=1;
	}
	else{
		ans[1]=0;
	}
	int p=0;
	if(islie==1){
		char check1,check2;
		check1=s1[2];
		check2=s2[2];
		if(check1-'A'>=3&&check2-'A'>=3){
			p=1;
		}
		if(check1-'A'<=2&&check2-'A'<=2){
			p=1;
		}
	}
	if(p==1){
		ans[2]=1;
	}
	else{
		ans[2]=0;
	}
	if(s1[2]-s2[2]==1||s1[2]-s2[2]==-1){
		ans[3]=1;
	}
	else
		ans[3]=0;
	if(ans[2]==0){
		ans[3]=0;
	}
	if(u==0){
		for(int i=0;i<4;i++){
			ans[i]=0;
		}
	}
	cout<<ans[0]<<ans[1]<<ans[2]<<ans[3];
	return 0;
}
