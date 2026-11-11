#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,a,all,le,ri,ans;
string b,c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(ll i=0;i<n;i++){
		cin>>a>>c;
		all+=a;
		for(ll i=0;i<a;i++)b+=c;
	}
	all/=2;
	le=all-1;
	ri=all+1;
	for(ll i=0;i<all;i++){
		if(b[le]!=b[ri])ans++;
		le--;ri++;
	}
	cout<<ans;
	return 0;
}
