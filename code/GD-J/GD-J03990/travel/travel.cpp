#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int ans[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		ans[1]=1;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&ans[1]){
		ans[2]=1;
	}
	if('A'<=s1[2]&&s1[2]<='C'&&'A'<=s2[2]&&s2[2]<='C'&&ans[2]){
		ans[3]=1;
	}else if('D'<=s1[2]&&s1[2]<='F'&&'D'<=s2[2]&&s2[2]<='F'&&ans[2]){
		ans[3]=1;
	}
	int k1=s1[2]-'0',k2=s2[2]-'0';
	if(k1+1==k2&&ans[3]){
		ans[4]=1;	
	}else if(s1[2]=='D'&&s2[2]=='F'&&ans[3]){
		ans[4]=1;
	}else if(k2+1==k1&&ans[3]){
		ans[4]=1;
	}
	for(int i=1;i<=4;i++)cout<<ans[i];
	return 0;
}
