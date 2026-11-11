#include<bits/stdc++.h>
using namespace std;
string c1,s1;
string c2,s2;
int ans[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		ans[1]=1;
		if(s1[1]==s2[1]&&s1[0]==s2[0]){
		ans[2]=1;
		if((s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')||(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F')){
			ans[3]=1;
			if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')||(s2[2]=='A'&&s1[2]=='B')||(s2[2]=='B'&&s1[2]=='A')||(s2[2]=='B'&&s1[2]=='C')||(s2[2]=='C'&&s1[2]=='B')){
		ans[4]=1;
	   }
	  }
	 }
	}
	for(int i=1;i<=4;i++){
		cout<<ans[i];
	}
	return 0;
} 
