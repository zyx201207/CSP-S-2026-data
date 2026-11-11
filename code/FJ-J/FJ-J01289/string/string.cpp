#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	while(n--){
		int a;
		char c;
		cin>>a>>c;
		while(a--)s+=c;
	}
	int ans=0;
	int l=0,r=s.size()-1;
	while(r>l){
		if(s[l]!=s[r])ans++;
		l++;
		r--;
	}
	cout<<ans;
	return 0;
}
