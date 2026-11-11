#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5+10;
ll n,cnt = 0,ans = 0,len;
ll k[N];
string s;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>k[i]>>c[i];
		for(int j = 1;j<=k[i];j++){
			s.push_back(c[i]);
		}
	}
	len = s.size();
	for(int i = 0;i<len/2;i++){
		if(s[i]!=s[len-i-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
