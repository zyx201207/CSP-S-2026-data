#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5,M=7;long long a[N],d;
int n,T,cnt[N],cnt1[N][M],cnt2[N][M],pre[N];
/*
0: 1
1: 2
2: +
3: 11
4: 12/1+
5: 22/2+
6: 111/112/11+
*/
inline void upd(int x,int L,int R) {//O(1)
	cnt[x]=0;
	for(int i=L;pre[i]<=x&&i<=R;i++)cnt[x]+=cnt[i];
	cnt[x]=min(cnt[x],3);return;
}
inline int gettyp(int L,int R) {//O(1)
	if(cnt[L]==3)return 2;if(L==R)return cnt[L]-1;if(cnt[L]==2)return 5;
	if(L+1==R)return min(2,cnt[R])+2;if(cnt[L+1]>=2)return 4;return 6;
}
inline void init(int x,int typ) {
	if(typ<=2){cnt[x]=typ+1;cnt[x+1]=cnt[x+2]=0;return;}
	if(typ==3||typ==4) {
		cnt[x]=1;cnt[x+1]=typ-2;cnt[x+2]=0;return;
	}
	if(typ==5){cnt[x]=2;cnt[x+1]=3;cnt[x+2]=0;return;}
	cnt[x]=1;if(typ==6){cnt[x+1]=1;cnt[x+2]=3;return;}
	cnt[x+1]=3;cnt[x+2]=3;return;
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%*d %d",&T);
	for(;T--;) {
		scanf("%d %lld",&n,&d);
		for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
		a[n+1]=a[n]+d+1;a[n+2]=a[n+1]+d+1;pre[n+1]=n+1;pre[n+2]=n+2;
		for(int i=1;i<=n;i++)cnt[i]=0;
		for(int i=1,las=1;i<=n;i++) {
			for(;a[i]-a[las]>d;las++);pre[i]=las;
		}
		for(int x=1;x<=n;x++) {
			int L=pre[x],R=x-1;
			memset(cnt1[x],0x00,sizeof(cnt1[x]));
			memset(cnt2[x],0x00,sizeof(cnt2[x]));
			if(L>R)continue;//pre[x]=x
			for(int typ=0;typ<M;typ++) {
				init(x,typ);int y=x+(typ>=3)+(typ>=6);
				for(int i=L;i<=min(R,L+2);i++)upd(i,x,y);
				cnt1[x][typ]+=cnt1[L][gettyp(L,R)];
				cnt2[x][typ]+=cnt2[L][gettyp(L,R)];
				if(cnt[L]==3)continue;
				int lim=__lg(min(R,pre[x+2])-L+1),pos1=L-1;
				if(cnt[L]==1) {
					for(int i=lim;i>=0;i--)
						if(pos1+(1<<i)<=R) {
							upd(pos1+(1<<i),x,y);
							if(cnt[pos1+(1<<i)]==1)pos1+=(1<<i);
						}
					cnt1[x][typ]+=(pos1-L+1);
				}
				int pos2=pos1;
				for(int i=lim;i>=0;i--)
					if(pos2+(1<<i)<=R) {
						upd(pos2+(1<<i),x,y);
						if(cnt[pos2+(1<<i)]==2)pos2+=(1<<i);
					}
				cnt2[x][typ]+=(pos2-pos1);
			}
		}
		long long ans=0ll;
		for(int i=1;i<=n;i++)
			ans+=cnt2[i][0];
		printf("%lld\n",ans);
	}
	return 0;
}

