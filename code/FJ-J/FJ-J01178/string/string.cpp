#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,len=0,ans=0;
	cin>>n;
	string s;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		len+=a;
		for(int j=1;j<=a;j++)
			s+=c;
	}
	for(int i=0;i<len/2;i++){
		if(s[i]!=s[len-i-1])
			ans++;
	}
	cout<<ans;
}
