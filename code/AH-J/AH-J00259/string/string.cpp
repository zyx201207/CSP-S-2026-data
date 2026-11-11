#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,s[N],cnt;
long long ans=0;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		scanf("%lld",&x);
		char ch;
		cin>>ch;
		for(int i=cnt+1;i<=cnt+x;i++)s[i]=ch-'a'+1;
		cnt+=x;
	}
	for(int i=1;i<=cnt/2;i++)
		if(s[i]!=s[cnt-i+1])ans++;
	cout<<ans<<endl;
}
