#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
vector<char>s;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long a;
		char c;
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s.push_back(c);
		}
	}
	for(int i=0;i<n;i++){
		if(!(s[i]==s[n-i-1])){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
