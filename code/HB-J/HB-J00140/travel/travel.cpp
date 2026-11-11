#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int ans[4]={1,1,1,1};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<2;i++){
		if(c1[i]!=c2[i]){
			ans[0]=0;
			ans[1]=ans[0],ans[2]=ans[0],ans[3]=ans[0];
			break;
		}
	}
	for(int i=0;i<2;i++){
		if(s1[i]!=s2[i]){
			ans[1]=0;
			ans[2]=0;
			ans[3]=0;
			break;
		}
	}
	if(ans[1]){
		if(s1[2]<='C'&&s2[2]>='D'||s1[2]>='D'&&s2[2]<='C'){
			ans[2]=0;
			ans[3]=0;
		}
	}
	if(ans[2]){
		if(abs(s1[2]-s2[2])!=1) ans[3]=0;
	}
	for(int i=0;i<4;i++){
		cout<<ans[i];
	}
	return 0;
}
