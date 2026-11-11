#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s,ans;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		while(a--)s+=c;
	}
	string t;
	t=s;

	reverse(t.begin(),t.end());
	if(t==s){
		cout<<0;
		return 0;
	}
	int cnt=0;
	for(int i=0;i<t.size();i++){
		int j=s.size()-i-1;
		if(t[i]!=s[i]){
			t[i]=s[i];
			s[j]=s[i];
			cnt++;
		}
		if(t==s){
			cout<<cnt;
			return 0;
		}
	}
	return 0;
} 
