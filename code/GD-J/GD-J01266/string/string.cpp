#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+10;
int n,a;
ll ans;
char c[N];
struct node{
	ll h,e;
}pre[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c[i];
		pre[i].h=pre[i-1].e+1;
		pre[i].e=pre[i].h+a-1;
	}
	ll l=1,r=pre[n].e,x=1,y=n;
	while(l<r){
		if(l>=pre[x].e){
			x++;
		}
		if(r<=pre[y].h){
			y--;
		}
		ll MIN=min(pre[x].e-l+1,r-pre[y].h+1);
		if(c[x]!=c[y]){
			ans+=MIN;
		}
		l+=MIN;
		r-=MIN;
	}
	cout<<ans<<'\n';
	return 0;
}
