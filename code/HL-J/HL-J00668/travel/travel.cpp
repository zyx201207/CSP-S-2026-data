#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,a,b;
	int ans1=0,ans2=0,ans3=0,ans4=0;
	cin>>a>>s1>>b>>s2;
	if(a==b){
		ans1=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			ans2=1;
			if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C')){
				ans3=1;
				if(abs(s1[2]-s2[2])==1){
					ans4=1;
				}
			}
		}
	}
	cout<<ans1<<ans2<<ans3<<ans4; 
	
}
