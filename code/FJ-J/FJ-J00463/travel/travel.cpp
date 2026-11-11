#include<bits/stdc++.h>
using namespace std;
string aa,ab,ba,bb,ans;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>aa>>ab>>ba>>bb;
	if(aa==ba) ans=ans+"1";
	else ans=ans+"0";
	if(ab[0]==bb[0]&&ab[1]==bb[1]&&ans[0]=='1') ans=ans+"1";
	else ans=ans+"0";
	if((ab[2]=='A'||ab[2]=='B'||ab[2]=='C')&&(bb[2]=='A'||bb[2]=='B'||bb[2]=='C')&&ans[0]=='1'&&ans[1]=='1') ans=ans+"1";
	else if((ab[2]=='D'||ab[2]=='F')&&(bb[2]=='D'||bb[2]=='F')&&ans[0]=='1'&&ans[1]=='1') ans=ans+"1";
	else ans=ans+"0";
	if(ans[0]=='1'&&ans[1]=='1'&&ans[2]=='1'&&(char(ab[2]+1)==bb[2]||char(ab[2]-1)==bb[2])){
		ans=ans+"1";
	}else{
		ans=ans+"0";
	}
	cout<<ans;
	return 0;
}
