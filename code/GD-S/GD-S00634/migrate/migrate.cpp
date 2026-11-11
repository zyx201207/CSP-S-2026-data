#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define freop(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout);
#define endl '\n'
#define inf 0x7f7f7f7f
#define lb(x) ((x)&-(x))
#define pii pair<int,int>
#define fir first
#define sec second
#define mkp make_pair
const int N=2e6+5;
int C,T,n,debug,pre[N],nxt[N],bt[N];
ll d,x[N],ans,psm[N],nsm[N];

int main(){
	cin.tie(0)->ios::sync_with_stdio(0);
	cout.tie(0);
	freop("migrate");
//↑以上为初始化↑
//-------------------------------------------------
	cin >> C >> T;
	while(T--){
		cin >> n >> d,ans=0;
		for(int i = 1;i<=n;++i) cin >> x[i];
		if(n<4){
			cout << "0\n";
		}else if(C==11||C==12){
			ll t=x[2]-x[1];
			cout << (d<t*2?0:max(0ll,n-((ll)d/t*2-1))) << endl;
		}else if(C==13||C==14){
			for(int i = 1;i<=n;++i) psm[i]=nsm[i]=0;
			for(int i = 1,pr=1,nx=1;i<=n;++i){
				while(pr<i&&x[i]-x[pr]>d) ++pr;
				while(nx<n&&x[nx+1]-x[i]<=d) ++nx;
				++psm[pr];++nsm[nx];
			}
			for(int i = 1;i<n;++i)
				ans+=nsm[i+1]*psm[i];
			cout << ans << endl;
		}else{
			for(int i = 1,pr=1,nx=1;i<=n;++i){
				while(pr<i&&x[i]-x[pr]>d) ++pr;
				while(nx<n&&x[nx+1]-x[i]<=d) ++nx;
				pre[i]=pr,nxt[i]=nx;
			}
			for(int i = 1,l;i<=n;++i)
				for(int j = i+3,r,fl;j<=n;++j){
					for(int k = i;k<=j;++k) bt[k]=0;
					l=i,r=j,fl=0;
					while(l<=j&&nxt[l]>l) l=nxt[l],++bt[l];
					while(r>i&&pre[r]<r&&fl<=1) r=pre[r],fl+=(bt[r+1]&&!bt[r]);
					ans+=(fl==1);
				}
			cout << ans << endl;
		}
	}
	return 0;
}

