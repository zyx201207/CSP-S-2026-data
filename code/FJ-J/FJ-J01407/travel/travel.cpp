#include<bits/stdc++.h>
using namespace std;
#define int long long
string s,s1,s2,s3,ans="0000";
bool same(string s1,string s3){
	if(s1[2]>='A'&&s1[2]<='C'&&s3[2]>='D'&&s3[2]<='F'){
		return false;
	}
	if(s1[2]>='D'&&s1[2]<='F'&&s3[2]>='A'&&s3[2]<='C'){
		return false;
	}
	return true;
}
bool next(string s1,string s3){
	if(abs(s1[2]-s3[2])==1) return true;
	return false;
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s>>s1>>s2>>s3;
	bool pd=true;
	if(s==s2){
		ans[0]='1';
	}else{
		pd=false;
	}
	if(s1[0]==s3[0]&&s1[1]==s3[1]&&pd){
		ans[1]='1';
	}else{
		pd=false;
	}
	if(same(s1,s3)&&pd){
		ans[2]='1';
	}else{
		pd=false;
	}
	if(next(s1,s3)&&pd){
		ans[3]='1';
	}else{
		pd=false;
	}
	cout<<ans;
	return 0;
}
