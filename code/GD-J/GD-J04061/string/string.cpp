#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin>>n;
	string s="";
	while(n--){
		int a;cin>>a;
		char c;cin>>c;
		s+=string(a,c);
	}
	int l=0,r=s.size()-1;
	int ans=0;
	while(l<r){
		if(s[l]!=s[r]) ans++;
		l++;r--;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
