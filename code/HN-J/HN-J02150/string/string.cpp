#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[1000005],ans;
string s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		char q;
		cin>>a[i]>>q;
		for(int j=1;j<=a[i];j++){
			s+=q;
		}
	}
	for(int i=0;i<s.size();i++){
		if(s[i]!=s[s.size()-i-1]){
			ans++;
		}
	}
	cout<<ans/2;
	return 0;
}
