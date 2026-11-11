#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string ans;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1==c2){
		ans+='1';
	}else{
		ans="0000";
		cout << ans;
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		ans+='1';
	}else{
		ans="1000";
		cout << ans;
		return 0;
	}
	if((s1[2]>='A'&&s1[2]<='C')&&(s2[2]>='A'&&s2[2]<='C')){
		ans+='1';
	}else{
		if((s1[2]>='D'&&s1[2]<='F')&&(s2[2]>='D'&&s2[2]<='F')){
			ans+='1';
		}else{
			ans="1100";
			cout << ans;
			return 0;
		}
	}
	if((s1[2]>='A'&&s1[2]<='C')&&(s2[2]>='A'&&s2[2]<='C')){
		if((s1[2]=='A'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='A')){
			ans+='0';
		}else{
			ans+='1';
		}
		cout << ans;
		return 0;
	}	
	ans+='1';
	cout << ans;
	return 0;
}

