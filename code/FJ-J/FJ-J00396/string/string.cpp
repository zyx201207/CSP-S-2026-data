#include<bits/stdc++.h>
using namespace std;
string s,r;
string p;
typedef long long LL;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	LL n,x;
	cin>>n;
	while(n--){
		cin>>x>>p;
		while(x--){
			s+=p;
			r+=p;
		}
	}
	reverse(r.begin(),r.end());
	if(s==r){
		cout<<0;
		return 0;
	}
	LL j,ans=0;
	for(j=0;j<s.size();j++){
		if(s[j]!=r[j]){
			ans++;
		}
	}
	cout<<(ans+2-1)/2;
	return 0;
} 
