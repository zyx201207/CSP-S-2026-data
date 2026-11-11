#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=(j);i<=(k);++i)
#define dwn(i,j,k) for(int i=(j);i>=(k);--i)
using namespace std;
#define ll long long
const int N=2e5+7;
int n,m,a[N],st[N],cnt,tt[N];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	rep(i,1,n)cin>>a[i];
	ll ans=0;cnt=n;
	rep(i,1,n)st[i]=i;
	dwn(j,30,0){
		int ww=0,tmp=0;
		rep(i,1,cnt){
			if(a[st[i]]>>j&1)++ww;
		}if(ww>=m){
			rep(i,1,cnt){
				if(a[st[i]]>>j&1)tt[++tmp]=st[i];
			}cnt=tmp;
			rep(i,1,cnt)st[i]=tt[i];
			ans|=(1<<j);
		}
	}cout<<ans;
	return 0;
}
