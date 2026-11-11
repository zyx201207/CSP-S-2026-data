//GZ-J00025 贵阳市白云区华师一学校 吴星汉 
#include <bits/stdc++.h>
#define ll long long
using namespace std;
string ans,c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		ans+='1';
		if(s1[0]==s2[0] && s1[1]==s2[1]){
			ans+='1';
			if(('C'>=s1[2] && 'C'>=s2[2]) || ('D'<=s1[2] && ('D'<=s2[2]))){
				ans+='1';
				if(abs((ll)(s1[2])-(ll)(s2[2]))==1){
					ans+='1';
				}
				else ans+='0';
			}
			else ans+="00";
		}
		else ans+="000";
	}
	else{
		ans+="0000";
	}
	cout<<ans;
	return 0;
}
