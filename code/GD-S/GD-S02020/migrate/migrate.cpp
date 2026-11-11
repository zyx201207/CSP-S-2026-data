#include <bits/stdc++.h>
#define N 2000005
#define ll long long
#define fi first
#define se second
using namespace std;
int n,r[N],g[N],p[N],lst,c,T;
ll a[N],d,ans;
queue<pair<int,pair<int,int> > > q;
inline void read(ll &x){
	x=0;
	char ch=getchar();
	int f=1;
	while(ch>57||ch<48){
		if(ch=='-') f=-1;
		ch=getchar();
	} 
	while(ch>=48&&ch<=57){
		x=x*10+(ch^48);
		ch=getchar();
	}
	x*=f;
}
inline void readd(int &x){
	x=0;
	char ch=getchar();
	while(ch>57||ch<48) ch=getchar();
	while(ch>=48&&ch<=57){
		x=x*10+(ch^48);
		ch=getchar();
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	readd(c),readd(T);
	while(T--){
		ans=0;
		readd(n),read(d);
		for(int i=1;i<=n;i++) read(a[i]);
		if(11>=c&&c<=12){
			ll x=a[2]-a[1],tmp=d/x;
			if(tmp<=1) puts("0");
			else printf("%lld\n",max(0ll,n-(tmp<<1)+1));
		}
		else{
			for(int i=1;i<=n;i++) r[i]=upper_bound(a+1,a+1+n,a[i]+d)-a-1;
			for(int i=1;i<=n;i++){
				fill(p+1,p+1+n,0); 
				p[1]=1;
				g[i]=1;
				while(!q.empty()) q.pop();
				q.push({i,{1,r[i]}});
				for(int j=i+1,k=1;j<=n;j++){
					while(!q.empty()&&q.front().se.se<j){
						p[q.front().se.fi]-=g[q.front().fi];
						q.pop();
					}
					while(!p[k]&&k<n) k++;
	//				if(p[k]>2){
	//					lst=j;
	//					break;
	//				}
					if(p[k]==2) ans++;
					g[j]=p[k];
					q.push({j,{k+1,r[j]}});
					p[k+1]+=g[j];
	//				if(i==1) printf("%d %d %d\n",j,k,g[j]);
				}
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
} /*
0 1
10 3
-1000000000000000000 -999999999999999997 -999999999999999994 -999999999999999993 -999999999999999992 -999999999999999991 -999999999999999990 -999999999999999989 -999999999999999986 -999999999999999983

*/
