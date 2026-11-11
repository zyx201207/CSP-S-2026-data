#include<bits/stdc++.h>
using namespace std;
int ans[10];
string s1,s2,c1,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		ans[1]=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			ans[2]=1;
			if(s1[2]<'D'&&s2[2]<'D'){
				ans[3]=1;
				if(s1[2]=='B'||s2[2]=='B'){
					ans[4]=1;
				}
			}
			if(s1[2]>='D'&&s2[2]>='D'){
				ans[3]=1;
				ans[4]=1;
			}
		}
	}
	
	for(int i=1;i<=4;i++){
		cout<<char(ans[i]+'0');
	}
	return 0;
} 
