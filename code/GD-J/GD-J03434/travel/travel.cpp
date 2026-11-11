#include<bits/stdc++.h>
using namespace std;

bool side(char a){
	if(a=='A'||a=='B'||a=='C'){
		return 1;
	}
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	string ans;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		ans="1";
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			ans+="1";
			if(side(s1[2])==side(s2[2])){
				ans+="1";
				if(side(s1[2])==1&&abs(s1[2]-s2[2])==1){
					ans+="1";
				}else if(side(s1[2])==0){
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
		ans="0000";
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
