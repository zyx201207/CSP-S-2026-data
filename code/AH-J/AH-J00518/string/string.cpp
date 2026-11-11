#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,ans;
int t,sum;
string s;
string c;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>t;
		sum+=t;
		cin>>c;
		for(int j=1;j<=t;j++){
			s+=c;
		}
	}
	int l=0,r=sum-1;
	while(l<=r){
		if(s[l]!=s[r]){
			ans++;
			s[r]=s[l];
		}
		l++,r--;
	}
	cout<<ans;
	return 0;
}//50
