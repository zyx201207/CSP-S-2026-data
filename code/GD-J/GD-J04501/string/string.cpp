#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,sum;
string s,a;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i = 1;i<=n;i++){
		int x;
		string q;
		cin>>x>>q;
		string r = q + q + q + q + q + q + q + q + q + q;	//10
		string rr = r + r + r + r + r + r + r + r + r + r;	//100
		string rrr = rr + rr + rr + rr + rr + rr + rr + rr + rr + rr;	//1000
		string rrrr = rrr + rrr + rrr + rrr + rrr + rrr + rrr + rrr + rrr + rrr;
//		string rrrrr = rrrr + rrrr + rrrr + rrrr + rrrr + rrrr + rrrr + rrrr + rrrr + rrrr;
//		string rrrrrr = rrrrr + rrrrr + rrrrr + rrrrr + rrrrr + rrrrr + rrrrr + rrrrr + rrrrr + rrrrr ;
//		string rrrrrrr = rrrrrr + rrrrrr + rrrrrr + rrrrrr + rrrrrr + rrrrrr + rrrrrr + rrrrrr + rrrrrr + rrrrrr ;
//
//		for(int i = 1;i<=x / 1000000;i++)s += rrrrrr;
//		for(int i = 1;i<=(x / 100000) % 10;i++)s += rrrrr;
		for(int i = 1;i<=x / 10000;i++)s += rrrr;
		for(int i = 1;i<=(x / 1000) % 10;i++)s += rrr;
		for(int i = 1;i<=(x / 100) % 10;i++)s += rr;
		for(int i = 1;i<=(x / 10) % 10;i++)s += r;
		for(int i = 1;i<=x % 10;i++)s += q;
	}
	for(int i = 0;i<s.size();i++){
		a = s[i] + a;
	}
	for(int i = 0;i<s.size() / 2;i++){
		if(a[i] != s[i])sum++;
	}
	cout<<sum<<'\n';
	return 0;
}
