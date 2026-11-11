#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n=0,ans=0;
	string s="";
	cin>>n;
	for(int i=1;i<=n;i++){
		int a=0,t=0;
		char c;
		cin>>a>>c;
		t=a;
		while(t--){
			s+=c;
		}
	}
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-1-i]) ans++;
	}
	cout<<ans;
	
	return 0;
}
