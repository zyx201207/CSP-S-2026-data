#include<bits/stdc++.h>
using namespace std;

int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c,s,cn,sn,ans;
	cin>>c>>s>>cn>>sn;
	if(c==cn){
		ans[0]=1;
	}else{
		ans[0]=0;
	}
	if(s[0]==sn[0] && s[1]==sn[1]){
		ans[1]=1;
	}else{
		ans[1]=0;
	}
	if(s[2]=='A' || s[2]=='B' || s[2]=='C'){
		if(sn[2]=='A' || sn[2]=='B' || sn[2]=='C'){
			ans[2]=1;
		}else{
			ans[2]=0;
		}
		if(s[2]=='A' && sn[2]=='B'){
			ans[3]=1;
		}
		if(s[2]=='A' && sn[2]=='C'){
			ans[3]=0;
		}
		if(s[2]=='B' && sn[2]=='A'){
			ans[3]=1;
		}
		if(s[2]=='B' && sn[2]=='C'){
			ans[3]=1;
		}
		if(s[2]=='C' && sn[2]=='A'){
			ans[3]=0;
		}
		if(s[2]=='C' && sn[2]=='B'){
			ans[3]=1;
		}
	}else if(s[2]=='D' || s[2]=='E'){
		if(sn[2]=='D' || sn[2]=='E'){
			ans[2]=1;
			ans[3]=1;
		}
	}
	for(int i=0;i<=3;i++){
		cout<<ans[i];
	}
	return 0;
} 
