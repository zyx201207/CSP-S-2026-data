#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N(2e5+5);
int n,len,ans;
int a[N],lt[N],rt[N];
char c[N];
int find(int x){
	return upper_bound(lt+1,lt+n+1,x)-lt-1;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i]>>c[i];
		lt[i]=len+1;
		rt[i]=lt[i]+a[i]-1;
		len+=a[i];
	}
	for(int l=1,r=len;l<=r;){
		int dl(rt[find(l)]-l),dr(r-lt[find(r)]);
		int d(min(dl,dr)+1);
		if(c[find(l)]!=c[find(r)]) ans+=d;
		l+=d;
		r-=d;
	}
	cout<<ans;
}
