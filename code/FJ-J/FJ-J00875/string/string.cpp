#include <bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
long long n,a[MAXN];
char c[MAXN];
string s;
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(long long j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	for(long long i=0;i<=s.size()/2-1;i++){
		if(s[s.size()-i-1]!=s[i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}

