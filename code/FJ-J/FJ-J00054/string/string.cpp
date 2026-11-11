#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN=2e5+3;
int n,a[MAXN];
char c[MAXN],s[MAXN];
LL len=1; 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i] >> c[i];
		for(int j=1;j<=a[i];j++) s[len++]=c[i];
	}
	len--;
	LL ans=0;
	for(int i=1;i<=len;i++) if(s[i]!=s[len-i+1]) ans++;
	cout << (LL)(ans>>1) << '\n';
	return 0;
}
