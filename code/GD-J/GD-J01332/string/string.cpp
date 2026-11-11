#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e5+5;
int n,cnt,x,f[maxn],ans;
char c;
struct node{
	int d,e;
}a[maxn];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i].d);
		cin>>c;
		a[i].e=c-'a'+1;
		cnt+=a[i].d;
		f[i]=cnt;
	}
	for(int i=1;i<=cnt/2;i++){
		int p=lower_bound(f+1,f+1+n,i)-f;
		int w=lower_bound(f+1,f+1+n,cnt-i+1)-f;
		if(a[p].e!=a[w].e) ans++;
	}
	cout<<ans;
	return 0;
}
