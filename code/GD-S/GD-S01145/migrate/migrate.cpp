#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
bool Mst;
int c,t;
int n,d;
int a[N];

namespace BF {
	int f[N];
	int cnt[N];
	int solve() {
		int ans=0;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				f[j]=1e18,cnt[j]=0;
			}
			cnt[i]=1,f[i]=0;
			for(int j=i+1; j<=n; j++) {
				for(int k=j; k>=i; k--) {
					if(a[j]-a[k]>d) break;
					if(f[k]+1<f[j]) {
						f[j]=f[k]+1,cnt[j]=cnt[k];
					} else if(f[k]+1==f[j]) cnt[j]+=cnt[k];
				}
				cnt[j]=min(cnt[j],3ll);
				if(cnt[j]==2) ans++;
			}
		}
		return ans;
	}
}

namespace BF1 {
	int f[N];
	int cnt[N];
	int pr[N],sf[N];
	int pre[N],suf[N];
	int S0[N],S1[N];
	int f0[N],f1[N];
	int sf1[N];
	int solve() {
		a[0]=-2e18-100,a[n+1]=2e18+100;
		pre[1]=1,suf[n]=n;
		for(int i=2; i<=n; i++) {
			pre[i]=pre[i-1];
			while(a[i]-a[pre[i]]>d) pre[i]++;
		}
		for(int i=n-1; i; i--) {
			suf[i]=suf[i+1];
			while(a[suf[i]]-a[i]>d) suf[i]--;
		}
		//get pre suf
		int ans=0;
		for(int i=1; i<=n; i++) {
			pr[i]=sf[i]=0;
			f0[i]=f1[i]=0;
		}
		for(int i=n; i>=1; i--) {
			sf[i]+=f0[i];
			f0[pre[i]]++;
			if(pre[i]<i && suf[pre[i]]==i) f0[pre[i]]+=f0[i];
		}
		for(int i=1; i<=n; i++) {
			pr[i]+=f1[i];
			f1[suf[i]]++;
			if(suf[i]>i && pre[suf[i]]==i) f1[suf[i]]+=f1[i];
		}
		//l->x;y->r
		for(int i=1; i<=n; i++)
			S0[i]=S1[i]=0;
		for(int i=1; i<=n; i++) {
			if(pre[i]<=i-2) {
				S1[pre[i]]++;
			}
			if(suf[i]>=i+2) {
				S0[suf[i]]++;
			}
		}
		for(int i=2; i<n-1; i++) {
			int c0=0,c1=0;
			int s0=0,s1=0;
			s1=S1[i];
			s0=S0[i+1];
			int pos=pre[i];
			if(pos<i && a[i+1]-a[pos]<=d && a[i+2]-a[pos]>d) s0+=pr[pos];
			pos=suf[i+1];
			if(pos>i+1 && a[pos]-a[i]<=d && a[pos]-a[i-1]>d) s1+=sf[pos];
			ans=ans+s0*s1;
//			cerr<<i<<" "<<" "<<s0<<" "<<s1<<"\n";
		}
		//x->y (exist z,z+1)
		return ans;
	}
}

bool Med;
signed main() {
//	cerr<<(&Med-&Mst)/1048576.0<<"\n";
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	int sumn=0;
	while(t--) {
		cin>>n>>d;
		for(int i=1; i<=n; i++) {
			cin>>a[i];
		}
		if(n<=300 && sumn<=1000) {
			sumn+=n;
			int ans=BF::solve();
			int ans1=BF1::solve();
			cout<<ans<<"\n";
			continue;
		}
		sumn+=n;
		int ans1=BF1::solve();
		cout<<ans1<<endl;
		continue;
	}
}
/*
g++ migrate.cpp -o migrate -O2 -std=c++14 -static
./migrate

结论：s-(1)>x -(2)> y -(1)> t

15:29 start BF!
15:40 finish BF(O(n^3) 24pts)
15:40 prepare BF1(O(n^2))
15:47 	Debug BF1!
16:13 finish Debug,but 0pts add
16:46 有思路——挂拍，先写T4的暴力！
17:22 过啦！！！ 
*/
