#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a[200005],l=0,cnt=0,ans=0;
	char c[200005];
	string s;
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	for(int i=2;i<=n;i++){
		if(c[i]==c[i-1]){
			cnt++;
		}
	}
	if(cnt==n-1){
		cout<<0;
		return 0;
	} 
	for(int i=1;i<=n;i++){
		l+=a[i];
	}
	for(int i=0;i<l;i++){
		if(s[i]!=s[l+1-i]){
			ans++;
		}
	}
	cout<<ans/2;
	return 0;
} 
