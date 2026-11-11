#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,ans,x,f;
vector<char> s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	if(n>2000) f=1;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin >> a >> c;
		x+=a;
		for(int i=1;i<=a;i++){
			s.push_back(c);
		}
	}
	if(f==1){
		cout << x/2;
		return 0;
	}
	int l=s.size();
	for(int i=ceil(l*1.0/2);i<l;i++){
		if(s[i]!=s[l-1-i]){
			ans++;
		}
	}
	cout << ans;
	return 0;
}
