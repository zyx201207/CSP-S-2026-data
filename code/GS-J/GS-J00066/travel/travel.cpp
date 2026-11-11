#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	string ans;
	if(c1==c2){
		ans+='1';
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			ans+='1';

			char a=s1[2],b=s2[2];
			if((a<='C'&&b<='C') || (a>='D'&&b>='D')){
				ans+='1';
				if(abs(a-b)<=1||(a=='D'||b=='D')){
					ans+='1';
				}
			}
		}
	}	
	for(int i=ans.size();i<4;i++){
		ans+='0';
	}
	cout<<ans;
	return 0;
}
