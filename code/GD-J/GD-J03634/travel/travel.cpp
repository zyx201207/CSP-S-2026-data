#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,a2,b1,b2,ans="0000";
	cin >>a1>>a2>>b1>>b2;
	if(a1==b1){
		ans[0]='1';
		if(a2[0]==b2[0]&&a2[1]==b2[1]){
			ans[1]='1';
			if((a2[2]-'A'>2&&b2[2]-'A'>2)||(a2[2]-'A'<=2&&b2[2]-'A'<=2)){
				ans[2]='1';
				if(a2[2]=='F')a2[2]='E';
				if(b2[2]=='F')a2[2]='E';
				if(a2[2]-b2[2]==-1||a2[2]-b2[2]==1){
					ans[3]='1';
					cout <<ans;
				}else cout <<ans;
			}else cout <<ans;
		}else cout <<ans;
	}else cout <<ans;
	return 0;
}
