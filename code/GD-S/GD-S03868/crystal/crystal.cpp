#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
int n,j=1,ans=1;
ll m,a[N];
ll tr[N];
int lowbit(int x){
	return x&-x;
}
void add(int x,ll k){
	while(x<=n) tr[x]+=k,x+=lowbit(x);
}
ll query(int x){
	ll sum=0;
	while(x) sum+=tr[x],x-=lowbit(x);
	return sum;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		if(a[i]==a[i+1]){
			ans=max(ans,i+1-j+1);
			continue;
		}
		ll t=a[i+1]-a[i];
		while(j<=i&&m<t*(i-j+1)){
			m+=query(j);
			j++;
		}
		if(m>=t*(i-j+1)&&j<=i){
			m-=t*(i-j+1);
			add(j,t),add(i+1,-t);
			ans=max(ans,i+1-j+1);
		}
	}
	cout<<ans<<'\n';
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

*/
