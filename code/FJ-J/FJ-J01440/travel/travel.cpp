#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	string ans="0000";
	if(c1==c2){
		ans[0]='1';
	}else{
		cout<<ans;
		return 0;
	}
	string a1="",a2="";
	for(int i=0;i<2;i++){
		a1+=s1[i];
		a2+=s2[i];
	}
	if(a1==a2){
		ans[1]='1';
		if(s1[2]>s2[2]){
			char a=s2[2];
			s2[2]=s1[2];
			s1[2]=a;
		}
		if(s1[2]=='A'){
			if(s2[2]=='B'){
				ans[2]=ans[3]='1';
			}else if(s2[2]='C'){
				ans[2]='1';
			}
		}else if(s1[2]=='B'){
			if(s2[2]=='C'){
				ans[2]=ans[3]='1';
			}
		}else if(s1[2]=='C'){
			ans[2]=ans[3]='0';
		}else{
			ans[2]=ans[3]='1';
		}
	}
	
	cout<<ans;
	
	return 0;
}
