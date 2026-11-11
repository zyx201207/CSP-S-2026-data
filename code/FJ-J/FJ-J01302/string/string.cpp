#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ans=0;
	cin>>n;
	for(int i=0;i<n;i++){
		int a;
		char d;
		cin>>a>>d;
		for(int j=0;j<a;j++)s=s+d;
	}
	bool c=true;
	for(int i=1;i<s.size();i++){
		if(s[i]!=s[i-1])c=false;
	}
	if(c)cout<<0;
	else{
		int sym=s[0],cnt=1;
		for(int i=1;i<s.size();i++){
			if(s[i]==sym)cnt++;
			else break;
		}
		int cntt=0;
		for(int i=s.size();i>=1;i--){
			if(s[i]==sym)cntt++;
			else break;
		}
		if(cnt!=cntt)ans=ans+abs(cnt-cntt);
		cout<<ans;
	}
} 
