#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string c1,s1,c2,s2,ans;
	cin>>c1>>s1>>c2>>s2;
	char maxx=max(s1[2],s2[2]);
	char minn=min(s1[2],s2[2]);
	if(c1==c2){
		ans+="1";
		if(s1[1]==s2[1]){
			ans+="1";
			if((s1[2]<'D'&&s2[2]<'D')||(s1[2]>'C'&&s2[2]>'C')){
				ans+="1";
				if(maxx-minn==1){
					ans+="1";
				}else{
					ans+="0";
				}
			}else{
				ans+="00";
			}
		}else{
			ans+="000";
		}
	}else{
		ans+="0000";
	}
	cout<<ans;
	return 0;
} 
