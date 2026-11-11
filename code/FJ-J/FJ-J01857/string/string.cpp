#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=200005;
int n,a[MAXN];
vector<char> s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int all=0;
	for(int i=1;i<=n;i++){
		int x;char c;
		cin>>x>>c;
		all+=x;
		for(int j=1;j<=x;j++){
			s.push_back(c);
		}
	}
	int cnt=0;
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[all-i-1]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
} 
