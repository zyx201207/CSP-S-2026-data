#include <bits/stdc++.h>
using namespace std;
long long n,a[200001],ans=0,l;
char c[200001];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(long long j=1;j<=a[i];j++) s+=c[i];
	}
	l=s.size();
	for(int i=0;i<l/2;i++) if(s[i]!=s[l-i-1]) ans++;
	cout<<ans;
	return 0;
}
