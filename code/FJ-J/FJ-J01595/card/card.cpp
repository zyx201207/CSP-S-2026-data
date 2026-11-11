#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const long long N=5e5+10;
long long n,m,cnt,a[N],p[N],q[N],ans[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;++i) cin>>a[i];
	for(long long k=1;k<=n;++k){
		memset(p,n+1,sizeof(p));
		memset(q,0,sizeof(q));
		long long u;
		for(long long i=k;i<=n;++i){
			u=p[a[i]];
			if(u<=cnt){
				for(long long j=u+1;j<=cnt;++j)
					p[q[j]]=0x3f3f3f3f,q[j]=0;
				cnt=p[a[i]];
			}
			else{
				q[++cnt]=a[i];
				p[a[i]]=cnt;
			}
		}
		for(long long i=1;i<=m;++i)
			if(p[i]<=cnt&&q[p[i]]) ans[i]++;
	}
	for(long long i=1;i<=m;++i)
		cout<<ans[i]<<" ";
	return 0;
}
