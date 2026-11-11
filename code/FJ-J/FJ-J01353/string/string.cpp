#include<bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a*b/__gcd(a,b)
#define lowbit(x) x&(-x)
#define pii pair<int,int>
using namespace std;

void Code(){
	int n;cin>>n;
	string s="";int l=0;
	for(int i=1;i<=n;i++){
		int a;char c;cin>>a>>c;
		for(int j=1;j<=a;j++)s+=c;
		l+=a;
	}
	int ans=0;
	for(int i=0;i<l/2;i++){
		if(s[i]!=s[l-i-1])ans++;
	}
	printf("%lld",ans);
}

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int t;t=1;
	while(t--)Code();
	return 0;
}

