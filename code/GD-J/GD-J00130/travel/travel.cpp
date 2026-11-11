#include <bits/stdc++.h>
using namespace std;
int c1,c2;
int ans1,ans2,ans3,ans4;
char s1[5],s2[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1;
	for(int i=0;i<3;i++){
		cin>>s1[i];
	}
	cin>>c2;
	for(int i=0;i<3;i++){
		cin>>s2[i];
	}
	if(c1==c2){
		ans1=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			ans2=1;
			if(s1[2]=='A'&&s2[2]=='B'||s1[2]=='B'&&s2[2]=='C'||s1[2]=='D'&&s2[2]=='F'){
				ans3=1;
				ans4=1;
			}
			else if(s2[2]=='A'&&s1[2]=='B'||s2[2]=='B'&&s1[2]=='C'||s2[2]=='D'&&s1[2]=='F'){
				ans3=1;
				ans4=1;
			}
			else if(s1[2]<='C'&&s2[2]<='C'){
				ans3=1;
			}
		}
	}
	cout<<ans1<<ans2<<ans3<<ans4;
	return 0;
} 
