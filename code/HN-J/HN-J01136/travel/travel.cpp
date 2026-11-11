#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3) cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	int f=1;
	for(int i=0;i<=1;i++){
		if(s2[i]!=s4[i]){
			f=0;
			break;
		}
	}
	if(f) cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	if((s2[2]=='A'||s2[2]=='B'||s2[2]=='C')&&(s4[2]=='A'||s4[2]=='B'||s4[2]=='C')||(s2[2]=='D'||s2[2]=='E')&&(s4[2]=='D'||s4[2]=='E')) cout<<"1";
	else{
		cout<<"00";
		return 0;
	}
	if(abs(s2[2]-s4[2])==1){
		if(s2[2]=='C'&&s4[2]=='D') cout<<"0";
		else cout<<"1";
	}
	else cout<<"0";
	return 0;
}

