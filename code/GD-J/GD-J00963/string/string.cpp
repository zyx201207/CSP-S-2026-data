#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	s=" "+s;
	long long r=0;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		r+=a;
		while(a--)s+=c;
	}
	int ans=0;
	for(int i=1;i<=r/2;i++,r--){
		if(s[i]!=s[r]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
