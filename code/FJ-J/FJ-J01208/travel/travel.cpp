#include<bits/stdc++.h>
using namespace std;
	string c1,s1,c2,s2,ans={"0000"};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		ans[0]='1'; 
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
		ans[1]='1';
		if(s1[2]>='A'&&s1[2]<='C'){
		if(s2[2]>='A'&&s2[2]<='C'){
			ans[2]='1';
		}
	}
		if(s1[2]>='E'&&s1[2]<='F'){
		if(s2[2]>='E'&&s2[2]<='F'){
			ans[2]='1';
		}
	}
	if(s1[2]=='A'){
		if(s2[2]=='B'){
			ans[3]='1';
		}
	}
		if(s1[2]=='B'){
		if(s2[2]=='A'||s2[2]=='C'){
			ans[3]='1';
		}
	}
		if(s1[2]=='C'){
		if(s2[2]=='B'){
			ans[3]='1';
		}
	}
		if(s1[2]=='E'){
		if(s2[2]=='F'){
			ans[3]='1';
		}
	}
		if(s1[2]=='F'){
		if(s2[2]=='E'){
			ans[3]='1';
		}
	}
	}
	
	}

	cout<<ans;
	return 0;
} 
