#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,a2,b1,b2;
	cin>>a1>>a2>>b1>>b2;
	bool ans[5]={true,true,true,true,false};
	if(a2[2]=='A'||a2[2]=='B'||a2[2]=='C'){
		if(b2[2]=='A'||b2[2]=='B'||b2[2]=='C'){
			if(a2[2]=='A'&&b2[2]=='B')ans[4]=true;
			if(a2[2]=='B'&&(b2[2]=='A'||b2[2]=='C'))ans[4]=true;
			if(a2[2]=='C'&&b2[2]=='B')ans[4]=true;
		}else{
			ans[3]=false;
			ans[4]=false;
		}
	}else{
		if(b2[2]=='D'||b2[2]=='F'){
			if(a2[2]=='D'&&b2[2]=='F')ans[4]=true;
			if(a2[2]=='F'&&b2[2]=='D')ans[4]=true;
		}else{
			ans[3]=false;
			ans[4]=false;
		}
	}
	if(a1!=b1){
		ans[1]=false;
		ans[2]=false;
		ans[3]=false;
		ans[4]=false;
	}
	if(a2[0]!=b2[0]||a2[1]!=b2[1]){
		ans[2]=false;
		ans[3]=false;
		ans[4]=false;
	}
	for(int i=1;i<=4;i++){
		if(ans[i])cout<<1;
		else cout<<0;
	}
	return 0;
}
