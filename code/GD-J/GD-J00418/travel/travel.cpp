#include<iostream>
#include<string>

using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int a=(s1[0]-'0')*10+(s1[1]-'0'),b=(s2[0]-'0')*10+(s2[1]-'0');
	string ans="";
	if(c1==c2){
		ans+="1";
		if(a==b){
			ans+="1";
			if((((s1[2]>='A'&&s1[2]<='C')&&(s2[2]>='A'&&s2[2]<='C'))||((s1[2]>='D'&&s1[2]<='F')&&(s2[2]>='D'&&s2[2]<='F')))){
				ans+="1";
			}else{
				ans+="0";
			}
			if(ans[2]=='1'&&((s1[2]-s2[2])==1||(s1[2]-s2[2])==-1)){
				ans+="1";
			}else{
				ans+="0";
			}
		}else{
			ans+="000";
		}
	}else{
		ans+="0000";
	}
	
	
	cout<<ans<<"\n";
	return 0;
}
