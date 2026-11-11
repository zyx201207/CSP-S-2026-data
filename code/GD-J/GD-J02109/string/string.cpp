#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,ans;
string s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s+=c;
		}
	}
	int size=s.length();
	int r=size-1;
	for(int i=0;i<size/2;i++){
		if(s[i]!=s[r]){
			s[r]=s[i];
			ans++;
		}	
		r--;
	}
	cout<<ans;
	return 0;
} 
