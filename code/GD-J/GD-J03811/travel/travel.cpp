#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	string ans="";
	if(c1==c2){
		ans+='1';
		string ss1,ss2;
		for(int i=0;i<s1.size()-1;i++){//提取排数 
			ss1+=s1[i];
			ss2+=s2[i];
		}
		if(ss1==ss2){//同一排？ 
			ans+='1';
			char a=s1[2],b=s2[2];
			if(a>='A'&&a<='C'&&b>='A'&&b<='C'||a>='D'&&a<='F'&&b>='D'&&b<='F'){
				ans+='1';
				if(a=='A'&&b=='B'||a=='B'&&b=='A'||a=='B'&&b=='C'||a=='C'&&b=='B'||a=='D'&&b=='F'||a=='F'&&b=='D'){
					ans+='1';
				}
				else{
					ans+='0';
					cout<<ans;
					return 0;
				}
			}
			else{
				ans+="00";
				cout<<ans;
				return 0;
			}
		}
		else{
			ans+="000";
			cout<<ans;
			return 0;
		}
	}
	else{
		ans+="0000";
		cout<<ans;
		return 0;
	}
	cout<<ans;
	return 0;
}
