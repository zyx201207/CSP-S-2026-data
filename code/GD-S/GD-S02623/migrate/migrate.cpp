#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define x first
#define y second
inline int in() {
	static char ch;
	static int a,f;
	ch=getchar();
	a=0,f=1;
	for(; !isdigit(ch); ch=getchar())if(ch=='-')f=-1;
	for(; isdigit(ch); ch=getchar())a=(a<<1)+(a<<3)+ch-'0';
	return a*f;
}
const int N=2e6+123;
int n,d,a[N],ans,T,c;
inline void init() {
	n=in();
	d=in();
	ans=0;
	for(int i=1; i<=n; i++) a[i]=in();

	return ;
}
inline void work2() {
	static int l[5010],w[5010];
	for(int i=1; i<=n; i++) {
		memset(l,0x3f,sizeof(l));
		memset(w,0,sizeof(w));
		l[i]=0;
		w[i]=1;
		for(int j=i; j<=n; j++) {
			if(w[j]==2)ans++;
			if(l[j]>l[j-1]+1&&j!=i)break;
			for(int k=j+1; k<=n; k++) {
				if(a[k]-a[j]<=d) {
					if(l[k]>l[j]+1) {
						l[k]=l[j]+1;
						w[k]=w[j];
					} else if(l[k]==l[j]+1) {
						w[k]+=w[j];
					}
				} else break;
			}
		}
	}
	cout<<ans<<"\n";
}
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=in();
	T=in();
	while(T--) {
		init();
		if(c<=10) {
			work2();
		} else if(c==11||c==12) {
			if(a[3]-a[1]>d) {
				printf("0\n");
				continue;
			} else {
				d=d/(a[2]-a[1]);
				ans=max(n-d*2+1,0ll);
				printf("%lld\n",ans);
			}
		} else if(c==13||c==14) {

		}else if(c>=15&&c<=18){
			work2();
		}else{
			work2();//??
		}

	}
	return 0;
}
