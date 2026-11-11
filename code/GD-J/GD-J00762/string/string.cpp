#include<bits/stdc++.h>
using namespace std;
int t,a,ans,n;
char c;
string s=" ";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>t;
	while(t--) {
		cin>>a>>c;
		for(int i=1;i<=a;i++) {
			s+=c;
		}
		n+=a;
	}
	for(int i=1;i<=n/2;i++) {
		if(s[i]!=s[n-i+1]) {
			ans++;
		}
	}
	cout<<ans;
	return 0;
}

