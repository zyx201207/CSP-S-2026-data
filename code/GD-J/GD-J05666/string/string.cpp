#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	string s="";
	int r=0;
	for(int i=0;i<n;i++){
		int o;
		char p;
		cin>>o>>p;
		r+=o;
		for(int i=0;i<o;i++){
			s=s+p;
		}
	}
	int l=0,cnt=0;
	r--;
	while(l<r){
		if(s[l]==s[r]){
			l++;
			r--;
			continue;
		}
		cnt++;
		l++;
		r--;
	}
	cout<<cnt;
	return 0;
}
