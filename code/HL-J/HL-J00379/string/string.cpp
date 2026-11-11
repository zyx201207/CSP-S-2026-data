#include<bits/stdc++.h>
using namespace std;
#define int long long
int ans;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string a;
	int n;
	cin>>n;
	while(n--){
		int t;
		char c;
		cin>>t>>c;
		while(t--)a+=c;
	}
	for(int i=0;i<a.size()/2;i++){
		if(a[i]!=a[a.size()-i-1])ans++;
	}
	cout<<ans;
	return 0;
} 
