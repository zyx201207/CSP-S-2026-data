#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i,x,y,z) for(int i=x;i<=y;i+=z)
#define REP(i,x,y,z) for(int i=x;i>=y;i-=z)
void rd(int &x){
	int f=1;x=0;char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c<='9'&&c>='0')x=x*10+(c-'0'),c=getchar();
	x*=f;
}const int N=5e5+10;
int n,m,a[N],ans=1,cnt;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	rd(n),rd(m);FOR(i,1,n,1)rd(a[i]);
	sort(a+1,a+n+1);
	int l=1;FOR(r,1,n,1){
		cnt+=(a[r]-a[r-1])*(r-l);
		while(cnt>m&&l<=r){
			int res=a[r]-a[l-1];
			cnt-=res;l++;
		}ans=max(ans,r-l+1);
	}cout<<ans;
	return 0;
}