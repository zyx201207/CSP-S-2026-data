#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,sum=0;
string s,t;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		string y;
		cin>>x>>y;
		for(int i=1;i<=x;i++) s=s+y;
	}
	t=s;
	reverse(t.begin(),t.end());
	for(int i=0;i<s.size();i++)
		if(s[i]!=t[i]) sum++;
	cout<<sum/2;
	return 0;
}
