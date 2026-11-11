#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10; 
int n;
ll ans;
string s;
struct str{
	ll v;
	char c;
}a[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].v>>a[i].c;
		for(int j=0;j<a[i].v;j++){
			s=s+a[i].c;
		}
	}
	ll L=s.size();
	for(int i=0;i<L/2;i++){
		if(s[i]!=s[L-i-1]) ans++;
	}
	cout<<ans;
	return 0;
}
//Trick||Treat!
