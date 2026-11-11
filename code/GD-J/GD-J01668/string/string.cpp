#include<bits/stdc++.h>
using namespace std;
using LL=long long;
constexpr int N=2e5+10;
LL a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	string s;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++)s+=c[i];
	}
	LL ans=0;
	for(int i=0,j=s.size()-1;i<s.size()/2;i++,j--){
		if(s[i]!=s[j])ans++;
	}
	cout<<ans;
	return 0;
}
