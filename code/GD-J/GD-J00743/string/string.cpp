#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e6+9;
void solved(){
	string s;
	int n; cin >> n;
	while(n--){
		int len; string a; cin >> len >> a;
		while(len--)s+=a;
	}
	int t=s.size()/2-1,tt=s.size()/2;
	if(s.size()%2!=0)tt++;
	ll ans=0;
	for(int l=t,r=tt;l>=0;l--,r++){
		if(s[l]!=s[r])ans++;
	}
	cout << ans;
	
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
//	int t; cin >> t; while(t--)
	solved();
	return 0;
} 
