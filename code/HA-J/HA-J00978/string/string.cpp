#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
pair<long long,char>a[N];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i].first >> a[i].second;
		for(int j=1;j<=a[i].first;j++){
			s+=a[i].second;
		}
	}
	long long ans=0;
	for(int i=0;i<(s.size()+1)/2;i++){
		if(s[i]!=s[s.size()-1-i])ans++;
	}
	cout << ans;
	return 0;
}
