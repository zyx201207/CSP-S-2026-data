#include <bits/stdc++.h>
using namespace std;

char c1[5],s1[5],c2[5],s2[5];
int ans[5];
void compare(){
	for(int i=0;i<2;i++){
		if(c1[i]==c2[i])	continue;
		for(int i=0;i<4;i++)	ans[i]=0;
		return;
	}
	ans[0]=1;
	for(int i=0;i<2;i++){
		if(s1[i]==s2[i])	continue;
		for(int i=1;i<4;i++)	ans[i]=0;
		return;
	}
	ans[1]=1;
	if(s1[2]>='A'&&s1[2]<='C'){
		if(s2[2]>='A'&&s2[2]<='C')	ans[2]=1;
		else if(s2[2]>='D'){
			ans[2]=0;
			ans[3]=0;
			return;
		}
	}
	else if(s1[2]=='D'){
		if(s2[2]=='F')	ans[2]=1;
		else{
			ans[2]=0;
			ans[3]=0;
			return;
		}
	}
	else if(s1[2]=='F'){
		if(s2[2]=='D')	ans[2]=1;
		else{
			ans[2]=0;
			ans[3]=0;
			return;
		}
	}
	if(abs(s1[2]-s2[2])==1)	ans[3]=1;
	else if(s1[2]=='D'&&s2[2]=='F')	ans[3]=1;
	else if(s1[2]=='F'&&s2[2]=='D')	ans[3]=1;
	return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	compare();
	for(int i=0;i<4;i++)	cout<<ans[i];
	return 0;
} 
