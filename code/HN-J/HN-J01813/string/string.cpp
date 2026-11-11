#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,a,mx,ans;
map<string,long long>mp;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		string s;
		cin>>a>>s;
		ans+=a;
		mp[s]+=a;
		mx=max(mp[s],mx);
	}
	cout<<(mx==ans?0:mx);
	return 0;
}

