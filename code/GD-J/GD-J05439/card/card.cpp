#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500001];
int t[300005];
string s;
int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) cin>>a[i];
	for(int i=1; i<=n; i++) { //¾ÖÊý
		s="";
		for(int j=i; j<=n; j++) {
			if(s.find(to_string(a[j]))!=string::npos) {
				s.erase(s.find(to_string(a[j]))),s+=to_string(a[j]);
			} else s+=to_string(a[j]);
		}
		for(int i=0; i<s.size(); i++) t[s[i]-'0']++;

	}
	for(int i=1; i<=m; i++) cout<<t[i]<<" ";
	return 0;
}

