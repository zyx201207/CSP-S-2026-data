#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ans,tot;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		int t;
		string c;
		cin>>t>>c;
		for(int j=1;j<=t;++j){
			s+=c;
		}
	}
	int ans=0;
	for(int i=0;i<((s.size()+1)/2);++i){
		if(s[i]!=s[s.size()-1-i]){
			++ans;
		}
	}
	cout<<ans;
	return 0;
}
