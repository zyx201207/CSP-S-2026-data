#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e5+9;
vector<char> c;
void solved(){
	int n; cin>>n;
	int m=0;
	for(int i=1;i<=n;i++){
		int a;
		char s; cin>>a>>s;
		m+=a;
		while(a--) c.push_back(s);
	}
	ll ans=0;
	for(int i=0;i<m/2;i++) if(c[i]!=c[m-i-1]) ans++;
	cout<<ans;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	cout<<fixed<<setprecision(1);
//	int t; cin>>t; while(t--)
	solved();
	return 0;
}

