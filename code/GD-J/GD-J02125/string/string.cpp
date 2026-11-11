#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin>>n;
	string s,rev;
	while(n--){
		int a;char b;
		cin>>a>>b;
		while(a--) s=s+b;
	}
	rev=s;
	reverse(rev.begin(),rev.end());
	int cnt=0;
	if(s==rev){
		cout<<0;
		return 0;
	}
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=rev[i]) cnt++;
	}
	cout<<cnt;
	return 0;
}
