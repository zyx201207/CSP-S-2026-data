#include<bits/stdc++.h> 
using namespace std;

long long n,m,ans;
string s,a,t;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	s=' '+s;
	for(int i=1;i<=n;i++){
		cin >> m;
		cin >> a;
		for(int j=1;j<=m;j++){
			s=s+a;
		}
	}
	t=s;
	reverse(t.begin(),t.end());
	if(t==s){
		cout << 0;
		return 0;
	}
	long long l=1,r=s.size()-1;
	while(l<=r){
		if(s[l]==s[r]){
			l++;
			r--;
		}else{
			ans++;
			l++;
			r--;
		}
	}
	cout << ans;
	return 0;
}
