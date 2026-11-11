#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("travel.in","r",stdin);
//	freopen("travel.out","w",stdout);
	string c,s,c2,s2,num;
	int ans=0,ans2=0;
	cin>>c>>s>>c2>>s2;
	if(c[1]!=c2[1]){
		num+="0000";
	}else{
		num+="1";
		for(int i=0;i<2;i++){
			if(s[i]!=s2[i]){
				num+="000";
				ans=1;
			}
		}
		if(ans==0){
			num+="1";
			if(s[2]-'A'<3 && s2[2]-'A'<3){
				num+="1";
			}else if(s[2]-'A'>=3 && s2[2]-'A'>=3){
				num+="1";
			}else{
				num+="00";
				ans2=1;
			}
			if(s[2]-s2[2]<=1 && s[2]-s2[2]>=-1 && ans2==0){
				if(s[2]=='C' && s2[2]=='D') num+="0";
				else if(s[2]=='D' && s2[2]=='C') num+="0";
				else num+="1";
			}else if(ans2==0){
				num+="0";
			}
		}
	}
	cout<<num;
	return 0;
} 
