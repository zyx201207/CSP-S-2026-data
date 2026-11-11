#include<bits/stdc++.h>
#define int long long

using namespace std;

const int mod=1e9+7;
struct node{
	int k;
	string s;
} a[200005];

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int n;
	cin>>n;
	string s=" ";
	int cnt=0,ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].k>>a[i].s;
		cnt+=a[i].k;
		for(int j=1;j<=a[i].k;j++) s+=a[i].s;
	}
	for(int i=1;i<=s.size();i++){
		if(s[i]!=s[cnt-i+1]) ans++;
	}
	cout<<ans/2;
	return 0;
}
