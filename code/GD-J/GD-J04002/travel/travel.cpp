#include<bits/stdc++.h>
using namespace std;
string ca,sa,cb,sb,ans;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>ca>>sa>>cb>>sb;
	ans="0000";
	if(ca==cb){
		ans[0]='1';
		if(sa[0]==sb[0]&&sa[1]==sb[1]){
			ans[1]='1';
			if(((sa[2]!='D'&&sa[2]!='F')&&(sb[2]!='D'&&sb[2]!='F'))||((sa[2]=='D'||sa[2]=='F')&&(sb[2]=='D'||sb[2]=='F'))){
				ans[2]='1';
				if(abs(sa[2]-sb[2])==1){
					ans[3]='1';
				}
			}
		}
	}
	cout<<ans;
	return 0;
} 
