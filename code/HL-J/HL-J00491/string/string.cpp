#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,now=0,ans=0,l=0;
char s[1000000005];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++){
		int a;char b;
		cin >> a >> b;
		for(int j=now;j<now+a;j++){
			s[j] = b;
		}
		now += a;
		l+=a;
	}
	for(int i=0;i<l/2;i++){
		if(s[i] != s[l-1-i]){
			s[l+1-i] = s[i];
			ans++;
		}
	}
	cout << ans;
	return 0;
}
