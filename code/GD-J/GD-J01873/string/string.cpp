#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,a[N],ans;
char c[N];
string s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++)s+=c[i];
	}
	s=' '+s;
	n=s.size()-1;
	for(int i=1;i<=n/2;i++)if(s[i]!=s[n-i+1])ans++;
	cout<<ans<<'\n';
	return 0; 
} 
