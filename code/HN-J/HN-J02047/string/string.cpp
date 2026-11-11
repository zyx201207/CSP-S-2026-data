#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,ans=0;
string s;
int cnt[150];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char a;
		cin>>x>>a;
		cnt[a]+=x;
		while(x--){
			s+=a;
		} 
	}
	string w=s;
	reverse(w.begin(),w.end());
	if(w==s) cout<<0;
	else{
		for(int i=0;i<s.size();i++){
			if(s[i]!=s[s.size()-i-1]){
				if(cnt[s[s.size()-i-1]]>cnt[s[i]]) s[i]=s[s.size()-i-1];
				else s[s.size()-i-1]=s[i];
				ans++; 
			}
		}
		cout<<ans;
	}
	return 0;
}
