#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2,ans="";
	cin>>c1>>s1>>c2>>s2;
	if(c1 != c2){
		ans="0000";
		cout<<ans;
		return 0;
	}
	else{
		ans="1";
		int t1=(s1[0]-'0')*10+(s1[1]-'0');
		int t2=(s2[0]-'0')*10+(s2[1]-'0');
		if(t1==t2) ans=ans+'1';
		else{
			ans=ans+"000";
			cout<<ans;
			return 0;
		}
		if(s1[2]>='A' && s1[2]<='C' && s2[2]>='A' && s2[2]<='C' || s1[2]>='D' && s1[2]<='F' && s2[2]>='D' && s2[2]<='F'){
			ans=ans+'1';
			if(abs((s1[2]-'A')-(s2[2]-'A'))==1){
				ans="1111";
			}
			else ans=ans+'0';
		}
		else ans=ans+"00";
	}
	cout<<ans;
	return 0;
}
