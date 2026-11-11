#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    string s;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		char x1;
		cin>>x1;
		while(x--)s+=x1;
	}
	string tmp=s;reverse(tmp.begin(),tmp.end());
	if(tmp==s){
		cout<<0;
		return 0;
	}
	int ans=0,ans2=0;
	for(int i=0;i<(long long)s.size()/2;i++){
		if(s[i]!=s[s.size()-1-i])ans++;
	}
	for(int i=s.size()-1;i>(long long)s.size()/2;i--){
		if(s[i]!=s[s.size()-1-i])ans2++;
	}
	cout<<max(ans,ans2);
    return 0;
}
