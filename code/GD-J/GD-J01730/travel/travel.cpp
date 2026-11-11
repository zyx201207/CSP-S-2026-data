#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string ans;
bool judge(string x,string y){
	if(x[2]<'D'&&y[2]<'D'){
		return true;
	}else if(x[2]>'D'&&y[2]>'D'){
		return true;
	}return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		ans[0]='1';
		
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			ans[1]='1';
			
			if(judge(s1,s2)){
				ans[2]='1';
				
				if(s1[2]-s2[2]==1||s2[2]-s1[2]==1){
					ans[3]='1';
				}
			}
		}
	}
	for(int i=0;i<4;i++){
		if(ans[i]!='1') ans[i]='0';
	}
	for(int i=0;i<4;i++){
		cout<<ans[i];
	}
	return 0;
}
