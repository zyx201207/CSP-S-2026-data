#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+50;
int n;
ll m,ans=1,cnt=1;
ll a[N];
void solve(int id){
	priority_queue<ll,vector<ll>,greater<ll> > q;
	ll p=m,res=0;
	for(int i=1;i<id;i++){
		q.push(a[id]-a[i]);
	}
	while(!q.empty()){
		if(p>=q.top()) p-=q.top(),q.pop(),res++;
    	else break;
	}
	ans=max(ans,res+1); 
	return ;
}
void sl1(){
	ll k=0;
	for(int i=1;i<=n;i++){
		if(k+i<=m) ans++,k+=i;
		else break;
	}
	cout << ans;
}
void sl2(ll diff){
	ll k=0;
	for(int i=1;i<=n;i++){
		if(k+i*diff<=m) ans++,k+=i*diff;
		else break;
	}
	cout << ans;
}
int main(){
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    bool f1=1,f2=1;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
    	cin >> a[i];
    	if(a[i]!=i) f1=0;
	}
	for(int i=1;i<=n-2;i++){
		if(a[i+1]-a[i]!=a[i+2]-a[i+1]){
			f2=0;
			break;
		}
	}
	if(f1){
		sl1();
		return 0;
	}
	if(f2){
		cout << 7778;
		sl2(a[n]-a[n-1]);
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		solve(i);
	}
	cout << ans;
	return 0;
}
