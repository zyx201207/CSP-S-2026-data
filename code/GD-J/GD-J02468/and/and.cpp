#include<bits/stdc++.h>
#define IL inline
#define ll long long
#define ull unsigned long long
#define ri register int
#define F(i,a,b) for(ri i=a;i<=b;i++)
#define FF(i,a,b) for(ri i=b;i>=a;i--)
#define i128 __int128
#define vec vector
using namespace std;
const int N=1e4+5;
const ll inf=0x3f3f3f3f3f3f3f3fLL;
const double eps=1e-9;
int n,m,cnt[31][N],idx;
ll mx=-inf,a[N],ans;
bool vis[N];
/*
IL void dfs(int cnt,ll res){
	
}
*/
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	F(i,1,n) cin>>a[i];
	F(i,1,n){
		if(a[i]>mx){
			mx=a[i],idx=i;
		}
	}
	if(m==1){
		cout<<mx;
		return 0;
	}
	if(m==n){
		ans=mx;
		F(i,1,n){
			if(idx!=i) ans&=a[i];	
		}
		cout<<ans;
		return 0;
	}
	cout<<ans;
	return 0;
}
/*
in:
5 3
31 3 1 15 7
out:
7
*/

/*
怎么有进制题
好像还是个 dp
俩最不擅长的结合到一起了，完蛋
AFOed.
不管了都退役之战了
放手一搏吧别顾虑太多 

upd 11:48 退役快乐 
*/
