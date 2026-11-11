#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
long long a[maxn];
char c[maxn];
void solve(){
	int n;
	cin>>n;
	string s,t;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	long long len=s.size()-1;
	for(int i=0;i<=len;i++){
		t[i]=s[len-i];
	}
	long long cnt=0;
	for(int i=0;i<=(len+1)/2-1;i++){
		if(t[i]!=s[i]) cnt++;
	}
	cout<<cnt;
}//3 2 a 3 b 2 cTrick||Treat!
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	solve();
	return 0;
} 
