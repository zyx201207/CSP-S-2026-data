#include<bits/stdc++.h>
#define endl '\n'
#define getchar getchar_unlocked
#define int long long
using namespace std;
bool check(string a,string b){
	if(a[0]!=b[0])return 0;
	if(a[1]!=b[1])return 0;
	return 1;
}
string c,s,c2,s2,ans;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>c2>>s2;
	if(c!=c2){
		ans="0000";
		cout<<ans<<endl;
		return 0;
	}
	else ans+='1';
	if(check(s,s2))ans+='1';
	else{
		ans+="000";
		cout<<ans<<endl;
		return 0;
	}
	if(s[2]>='A'&&s[2]<='C'&&s2[2]>='A'&&s2[2]<='C'||((s[2]=='D'||s[2]=='F')&&(s2[2]=='D'||s2[2]=='F')))ans+='1';//雷霆判定 
	else{
		ans+="00";
		cout<<ans<<endl;
		return 0;
	}
	if(abs(s[2]-s2[2])==1)ans+='1';
	else ans+="0";
	cout<<ans<<endl;
	return 0;
}
// 和 一 位 大 模 擬 
