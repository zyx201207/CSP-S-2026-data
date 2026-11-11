#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	string s1,s2,c1,c2,ans="0000";
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		ans[0]='1';
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			ans[1]='1';
			if(s1[2]<='C'&&s1[2]>='A'&&s2[2]<='C'&&s2[2]>='A'){
				ans[2]='1';
				if(int(s1[2])-int(s2[2])==1||int(s2[2])-int(s1[2])==1){
					ans[3]='1';
					cout<<ans;
				}else{
					cout<<ans;
				}
			}else if(s1[2]=='D'||s1[2]=='F'&&s2[2]=='D'||s2[2]=='F'){
				ans[2]='1';
				ans[3]='1';
				cout<<ans;
			}else{
				cout<<ans;
			}
		}else{
			cout<<ans;
		}
	}else{
		cout<<ans;
	}
	return 0;
}
