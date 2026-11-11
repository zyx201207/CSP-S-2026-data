#include <bits/stdc++.h>
#define ll long long
#define up(i,a,b) for (int i=(a);i<=(b);i++)
#define down(i,a,b) for (int i=(a);i>=(b);i--)
using namespace std;
const int N=2e6+5;
int n;ll d,x[N],ans;
int lef[N],rig[N];
void prelr(int L,int R){
	int pos=L;
	up(i,L,R){
		while (x[i]-x[pos]>d) pos++;
		lef[i]=pos;
	}
	pos=R;
	down(i,R,L){
		while (x[pos]-x[i]>d) pos--;
		rig[i]=pos;
	}
//	cerr<<"lef:";up(i,L,R) cerr<<lef[i]<<' ';
//	cerr<<'\n';
//	cerr<<"rig:";up(i,L,R) cerr<<rig[i]<<' ';
//	cerr<<'\n';
}
ll f[N],g[N];//f:i到左边线路唯一的点个数 g:i到右边线路唯一的点个数
//rig[x]>rig[x-1]若干次到i即可
void prefg(int L,int R){
	up(i,L-1,R+1) f[i]=g[i]=0;
	up(i,L,R){
		f[i]++;//自己
		if (rig[rig[i]]>rig[rig[i]-1]) f[rig[i]]+=f[i];
	}
	down(i,R,L){
		g[i]++;
		if (lef[lef[i]]<lef[lef[i]+1]) g[lef[i]]+=g[i];
	}
//	cerr<<"f:";up(i,L,R) cerr<<f[i]<<' ';
//	cerr<<'\n';
//	cerr<<"g:";up(i,L,R) cerr<<g[i]<<' ';
//	cerr<<'\n';
}
//(i,k) 线路i->j->k,j=rig[i]
//则i->j-1->k && j-2->k不成立
//即{
//    rig[i]<k
//    rig[rig[i]]>=k
//    rig[rig[i]-1]>=k
//    rig[rig[i]-2]<k
//}

//{
//    lef[i]>k
//    lef[lef[i]]<=k
//    lef[lef[i]+1]<=k
//    lef[lef[i]+2]>k
//}
void solve1(int L,int R){
	if (L==R) return;
	prelr(L,R),prefg(L,R);
	up(i,L,R){
		int r=rig[rig[i]-1];
		int l=rig[i]+1;
		if (rig[i]-2>i) l=rig[rig[i]-2]+1;
		if (l>r) continue;
//		cerr<<i<<" ok "<<l<<' '<<r<<'\n';
		ans+=1ll*(r-l+1);//case1
		if (rig[rig[i]]==r){
			ans+=g[r]-1;//case2
			int nxt=rig[rig[i]];
			if (lef[lef[nxt]]==i) ans+=(f[i]-1)*(g[r]-1);//case4
		}
	}
	down(i,R,L){
		int l=lef[lef[i]+1];
		int r=lef[i]-1;
		if (lef[i]+2<i) r=lef[lef[i]+2]-1;
		if (l>r) continue;
		if (lef[lef[i]]==l) ans+=f[l]-1;//case3
	}
}
void solve(){
	cin>>n>>d;
	up(i,1,n) cin>>x[i];
	ans=0;
	int l=1;
	up(r,1,n) if (r==n||x[r+1]-x[r]>d) solve1(l,r),l=r+1;
	cout<<ans<<'\n';
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,t;cin>>c>>t;
	while (t--) solve();
	return 0;
}
