#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e6;
ll n,m;
ll a[N];
ll x[N],rear = 0;
ll ans;
ll cnt[70];
bool cmp(ll x,ll y){
	return x > y;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	//freopen("D:\\cspj\\down\\and\\and2.in","r",stdin);
	//freopen("D:\\cspj\\down\\and\\o.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int j = 0,t = a[i];
		while(t!=0){
			cnt[j] += (t & 1ll);
			t = (t>>1);
			j++;
		}
	}
	int p = 0;
	for(int i=0;i<=60;i++){
		if(cnt[i] >= m){
			p = i;
		}
	}
	for(int i=1;i<=n;i++){
		if((a[i]>>p)&1ll){
			rear++;
			x[rear] = a[i];
		}
	}
	sort(x+1,x+1+rear,cmp);
	ans = x[1];
	for(int i=2;i<=m;i++){
		ans = (ans & x[i]);
	}
	cout<<ans<<endl;
	return 0;
}
