#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define LL __int128
#define pb push_back
#define pf push_front
#define pof pop_front
#define pob pop_back
#define pii pair<int,int>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define pll pair<ll,ll>
#define pdi pair<double,int>
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
using namespace std;
inline ll read(){
	ll k=0;char c=getchar();bool f=0;
	while(!isdigit(c)){if(c=='-')f=1;c=getchar();}
	while(isdigit(c)){k=(k<<1)+(k<<3)+(c^48);c=getchar();}
	if(f)return -k;else return k;
}
inline char readc(){
	char c=getchar();
	while(!isgraph(c))c=getchar();
	return c;
}
inline string reads(){
	string s="";char c=getchar();
	while(!isgraph(c))c=getchar();
	while(isgraph(c)){s+=c;c=getchar();}
	return s;
}
void write(ll x){
	if(x>9)write(x/10);
	putchar((x%10)^48);
	return ;
}
const int N=5e5+10;
ll n,m,a[N],sum[N],ans;
inline bool check(int p,int i){return a[p]*(p-i+1)-(sum[p]-sum[i-1])<=m;}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)a[i]=read()+(ll)1e12;
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i)sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;++i){
		int l=1,r=n;
		ll pos;
		while(l<=r){
			int mid=l+r>>1;
			if(check(mid,i)){
				pos=mid;
				l=mid+1;
			}
			else r=mid-1;
		}
		ans=max(ans,pos-i+1);
	}
	cout<<ans<<'\n';
	return 0;
}
/*
10 20
20 -4 1 -8 5 -12 -8 9 -6 -20 

*/
