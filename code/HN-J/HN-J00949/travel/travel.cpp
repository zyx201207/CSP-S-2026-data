#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string ra,rb,xa,xb;
	cin>>ra>>rb>>xa>>xb;
	string ans;
	for(int i=0;i<4;i++){
		ans[i]='0';
	}
	if(ra==xa){
		if(rb[0]==xb[0]&&rb[1]==xb[1]){
			if(rb[2]>='A'&&rb[2]<='C'&&xb[2]>='A'&&xb[2]<='C'||rb[2]>='D'&&rb[2]<='F'&&xb[2]>='D'&&xb[2]<='F'){
				if(rb[2]=='A'&&xb[2]=='B'||rb[2]=='B'&&xb[2]=='A'||rb[2]=='B'&&xb[2]=='C'||rb[2]=='C'&&xb[2]=='B'||rb[2]=='D'&&xb[2]=='F'||rb[2]=='D'&&xb[2]=='F'){
					ans[3]='1';
				}
				ans[2]='1';
			}
			ans[1]='1';
		}
		ans[0]='1';
	}
	for(int i=0;i<4;i++){
		cout<<ans[i];
	}
	return 0;
}
