#include <bits/stdc++.h>
using namespace std;
long long n,a,ans;
string s,t;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>s;
		for(long long j=1;j<=a;j++){
			t+=s;
		}
	}
	int l=t.size();
	for(long long k=0;k<l;k++){
		if(t[k]!=t[l-1-k])ans++;
	}
	cout<<ans/2;
	return 0;
}
