#include<bits/stdc++.h>
using namespace std;
#define int long long
string s="";
int q;
char c;
int n;
bool h(string s1){
	for(int i=0;i<s1.size()/2+1;i++){
		if(s1[i]!=s1[s1.size()-i-1]){
			return false;
		}
	}
	return true;
}
int ans=0;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>q>>c;
		for(int j=1;j<=q;j++){
			s+=c;
		}
	}
	if(h(s)){
		cout<<0;
		return 0;
	}
	else{
		for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1]){
			ans++;
		}
	}
		cout<<ans;
}
	return 0;
}
