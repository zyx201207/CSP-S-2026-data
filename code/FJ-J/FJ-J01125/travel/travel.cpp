#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,ans="0000";
int re(string x){
	char c=x[2];
	if(c<='C') return 1;
	else return 2;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		ans[0]='1';
		if(s1[0]==s2[0] && s1[1]==s2[1]){
			ans[1]='1';
			if(re(s1)==re(s2)){
				ans[2]='1';
				if(abs(s1[2]-s2[2])==1){
					ans[3]='1';
				}
			}
		}	
	}
	
	cout<<ans<<endl;
	return 0;
}