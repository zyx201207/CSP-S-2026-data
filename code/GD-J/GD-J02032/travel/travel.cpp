#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	int ans[10];
	ans[1]=ans[2]=ans[3]=ans[4]=0;
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
		ans[1]=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			ans[2]=1;
			if((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')){
				ans[3]=ans[4]=1;
			}
			else if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C'){
				ans[3]=ans[4]=1;
				if(s1[2]!='B'&&s2[2]!='B'){
					ans[4]=0;
				}
			}
		}
	}
	cout<<ans[1]<<ans[2]<<ans[3]<<ans[4];
	return 0;
} 
