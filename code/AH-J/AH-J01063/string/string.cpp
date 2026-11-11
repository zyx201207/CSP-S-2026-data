#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
vector<char>s;
int n,tot=0,ans;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char y;
		cin>>x>>y;
		for(int j=1;j<=x;j++){
			s.push_back(y);
			tot++;
		}
	}
	for(int i=0;i<(tot+1)/2;i++)if(s[i]!=s[tot-i-1])ans++;
	cout<<ans;
	return 0;
}
