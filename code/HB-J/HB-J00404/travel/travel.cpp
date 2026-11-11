#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string ans;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int sum=(int)s1[2]+s2[2];
	//65 66 67 68 69 70
	//AB 131 AC 132 BC 133 DE 139
	if(c1==c2){
		ans+="1";
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			ans+="1";
			if(sum==131||sum==132||sum==133||sum==139){
				ans+="1";
				if(abs((int)(s1[2]-s2[2]))==1){
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
