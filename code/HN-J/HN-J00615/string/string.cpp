#include<bits/stdc++.h>
using namespace std;
long long n,ans;
long long a[500001];
char c[50001];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
		for(int j=1;j<=a[i];j++)s+=c[i];
	} 
	for(int i=0;i<s.size()/2;i++){
		int j=s.size()-i-1;
		if(s[i]!=s[j])ans++;
	}
	cout<<ans<<"\n";
	return 0;
}
