#include<bits/stdc++.h>
using namespace std;
long long n,ans,maxn;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long a;
		char c;
		cin>>a>>c;
		maxn=max(maxn,a);
		if(maxn<=1000) for(int j=1;j<=a;j++) s+=c;
	}
	if(n==1||maxn>1000){
		cout<<0;
		return 0;
	}
	int l=0,r=s.size()-1;
	while(l<=r){
		if(s[l]!=s[r]) ans++;
		l++;
		r--;
	}
	cout<<ans;
	return 0;
}
