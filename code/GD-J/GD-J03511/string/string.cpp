#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
struct node{
	ll cnt;
	char ch;
}a[N],b[N];
ll n,L;
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].cnt>>a[i].ch,L+=a[i].cnt;
	if(L&1){
		ll idx=0,f=0;
		ll nwL=0;
		for(int i=1;i<=n;i++){
			if(!f&&(nwL+a[i].cnt)*2>=L){
				f=1;
				ll c1=L/2-nwL;
				if(c1) b[++idx]={c1,a[i].ch};
				if(a[i].cnt-c1-1) b[++idx]={a[i].cnt-c1-1,a[i].ch};
			}
			else b[++idx]=a[i];
			nwL+=a[i].cnt;
		}
		n=idx;
		for(int i=1;i<=n;i++) a[i]=b[i];
	}
	ll l=1,r=n;
	ll res=0;
	char c1=a[l].ch,c2=a[r].ch;
	while(l<r){
		ll sz=min(a[l].cnt,a[r].cnt);
		if(c1!=c2) res+=sz;
		a[l].cnt-=sz,a[r].cnt-=sz;
		if(!a[l].cnt) l++,c1=a[l].ch;
		if(!a[r].cnt) r--,c2=a[r].ch;
	}
	cout<<res<<'\n';
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	while(T--) solve();
	return 0;
}
