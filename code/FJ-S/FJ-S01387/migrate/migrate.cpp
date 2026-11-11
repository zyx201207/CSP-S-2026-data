#include<bits/stdc++.h>
using namespace std;
const long long N=2000005;
const long long inf=1000000000ll;
long long c,_,n,d,x[N],f[N],g[N],r[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>_;
	while(_--){
		long long ans=0;
		cin>>n>>d;
		for(long long i=1;i<=n;++i)cin>>x[i];
		for(long long i=1;i<=n;++i){
			f[i]=g[i-1]=0ll;g[i]=1ll;r[0]=i;
			for(long long j=i+1,k=i;j<=n;++j){
				while(k<j&&x[j]-x[k]>d)++k;
				if(k<j){
					f[j]=f[k]+1;
					g[j]=g[r[f[k]]]-g[k-1];
					r[f[j]]=j;
					if(g[j]==2)++ans;
					g[j]=min(g[j],inf);
					g[j]+=g[j-1];
				} else break;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
