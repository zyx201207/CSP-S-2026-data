#include<bits/stdc++.h>
#define qwq return 0;
#define int long long
using namespace std;
int n,a[100005],ans,ok=1;
string s;
char c[100005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	for(int i=1;i<n;i++) if(a[i]!=a[i+1]) ok=0;
	if(ok){
		for(int i=1;i<=n/2;i++) if(c[i]!=c[n-i+1]) ans+=a[i];
		cout<<ans;
		qwq
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=a[i];j++) s+=c[i];
	int m=s.size();
	for(int i=0;i<m/2;i++) if(s[i]!=s[m-i-1]) ans++;
	cout<<ans;
	qwq
}
//Trick||Treat!
//RP++
//O(n*a[i])
//Ô¤¼Æ48%pts +
