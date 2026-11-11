#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[200005];
char c[200005];
map<char,int> mp;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s="";
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	if(n==1) cout<<0<<endl;
	if(n==2){
		int minn=1e9;
		for(int i=0;i<s.size();i++) mp[s[i]]++;
		for(int i=0;i<s.size();i++) {
			minn=min(minn,mp[s[i]]);
		}
		if(minn==s.size()) cout<<0;
		else cout<<minn<<endl;
	}
	if(s.size()%2==1){
		cout<<s.size()/2<<endl;
	}else cout<<s.size()/2<<endl;
	return 0;
}  
