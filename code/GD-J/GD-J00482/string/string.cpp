#include<bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
#define int long long
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,l=0,ans=0;
	string s="";
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		l+=a[i];
		for(int j=1;j<=a[i];j++)s+=c[i];
	}
	for(int i=0;i<l/2;i++){
		if(s[i]!=s[l-i-1])ans++;
	}
	cout<<ans;
	return 0;
}
