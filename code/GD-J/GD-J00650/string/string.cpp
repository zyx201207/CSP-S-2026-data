#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s="";
	char c1;
	int nn=n;
	while(n--){
		int x;
		char c;
		cin>>x>>c;
		while(x--) s+=c;
	}
	bool f=0;
	for(int i=1;i<s.size();i++) if(s[i]!=s[i-1])f=1;
	if(f==0){
		cout<<0;
		return 0;
	}
	int l=0,r=s.size(),ans=0;
	while(l<r){
		ans+=(s[l]!=s[r]);
		l++,r--;
	}
	cout<<ans;
	return 0;
}
