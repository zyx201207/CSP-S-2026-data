#include<bits/stdc++.h>
using namespace std;
char BEGIN;
namespace hwq{
	#define ll long long
	#define pb push_back
	char buf[1<<21],*_S,*_T;
	#define gc (_S==_T&&(_T=(_S=buf)+fread(buf,1,1<<21,stdin),_S==_T)?EOF:(*_S++))
	inline ll read(){ll x=0;bool f=0;char ch=gc;while(!isdigit(ch)&&ch!='-') ch=gc;if(ch=='-') f=1,ch=gc;while(isdigit(ch)) x=(x<<3)+(x<<1)+ch-48,ch=gc;return f?-x:x;}
	const int MAXN=2e6+5;
	int ci,ti;
	int n;
	int nxt[MAXN];
	ll d,x[MAXN];
	inline bool check(int a,int b){
		return x[b]-x[a]<=d;
	}
	int main(){
		ci=read(),ti=read();
//		int T=0;
		while(ti--){
			n=read(),d=read();
			for(int i=1;i<=n;i++) x[i]=read();
//			if(++T!=4) continue;
			ll ans=0;
			for(int i=1,j=1;i<=n;i++){
				while(j<n&&check(i,j+1)) j++;
				nxt[i]=j;
			}
			for(int i=1;i<=n;i++) if(nxt[i]!=i){
				int l=i,r=i;
//				printf("solve(%d)\n",i);
				bool bo=0;
				int tt=i,t=i-1;
				while(l<=r){
					if(nxt[r]==r) break;
//					printf("(%d,%d) %d\n",l,r,bo);
					if(l==r) l=r+1,r=nxt[r];
					else{
						if(!bo&&nxt[r-1]==nxt[r]){
							bo=1;
							if(r-t>=3) l=nxt[r-2]+1,r=nxt[r];
							else l=r+1,r=nxt[r];
						}else{
							if(!bo){
								if(r-t>=3) ans+=nxt[r-1]-nxt[r-2];
								else ans+=nxt[r-1]-r;
							}
							l=nxt[r-1]+1,r=nxt[r];
						}
					}
					t=tt,tt=nxt[tt];
					if(bo) ans+=r-l+1;
				}
//				printf("ans : %lld\n",ans);
			}
			printf("%lld\n",ans);
		}
		return 0;
	}
}
char END;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
#ifdef XYHQ
	printf("Memory : %lld MB\n",(&BEGIN-&END)>>20);
//	freopen("1.in","r",stdin);
	freopen("migrate5.in","r",stdin);
//	freopen("migrate.out","w",stdout);
#else
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
#endif
//	clock_t begin=clock();
	hwq::main();
//	clock_t end=clock();
//	cerr<<endl<<"Time : "<<((double)end-(double)begin)/1000.0<<" s"<<endl;
	return 0;
}
