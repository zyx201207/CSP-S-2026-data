#include <bits/stdc++.h>
#define int long long
using namespace std;
int p(string s){
	string k;
	for(int i=s.size()-1;i>=0;i--){
		k+=s[i];
	}
	if(k==s){
		return 1;
	}
	else{
		return 0;
	}
}
int gai(string s){
	string k;
	for(int i=s.size()-1;i>s.size()/2;i--){
		k+=s[i];
	}
	int cnt=0;
	for(int i=0;i<s.size()/2;i++){
		if(k[i]!=s[i]){
			cnt++;
		}
	}
	return cnt;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	string s;
	for(int i=1;i<=n;i++){
		int k;
		char a;
		cin>>k;
		cin>>a;
		for(int i=1;i<=k;i++){
			s+=a;
		}
	}
	cout<<s<<endl;
	if(p(s)==1){
		cout<<0;
		return 0;
	}
	cout<<gai(s);
	return 0;
}

