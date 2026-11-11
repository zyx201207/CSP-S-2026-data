#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[200005],now,ans;
char s[200000005];
char c[200005];
ll x;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s[now+j]=c[i];
			x=now+j;
		}
		now+=a[i];
	}
	for(int i=1;i<=x/2;i++){
		ll j=x;
		if(s[i]!=s[j-i+1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
