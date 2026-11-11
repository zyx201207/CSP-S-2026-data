#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+5;
typedef long long ll;
ll tmp=0;
ll loggg=0;
ll logg=0;
ll n,m;
ll a[maxn];
ll xx=0;
ll ans=1;
//现在16:02，我是上午j-00536还是563来着，忘了
//燕大米线挺好吃
//T4文件有惊喜 
bool cmp(ll x,ll y){
	return x>y;
}
ll find(ll x){
	ll cnt=0;
	tmp=m;
	for(int i=1;i<=n;i++){
		if(a[i]>x) continue;
		if(a[i]==x) cnt++;
		if(a[i]<x){
			if(max(x-a[i],a[i]-x)>tmp){
				loggg=i;
				logg=tmp;
				return cnt;
			}
			else {
				cnt++;
				tmp-=max(x-a[i],a[i]-x);
			}
		}
	}
	loggg=n;
	return cnt;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	ans=max(ans,find(a[1]));
	if(ans==n){
		cout<<n;
		return 0;
	}
	for(int i=2;i<=n;i++){
		if(a[i]==a[i-1]) continue;
		tmp=(a[i-1]-a[i])*(loggg-i+1)+logg;
//		cout<<tmp<<endl;
		for(int j=max(loggg,i);j<=n;j++){
			if(max(a[i]-a[j],a[j]-a[i])>tmp){
				loggg=j;
				ans=max(ans,j-1-i);
				logg=tmp;
				break;
			}
			else{
				tmp-=max(a[i]-a[j],a[j]-a[i]);
				ans=max(ans,j-i+1);
			}
			
		}
		logg=tmp;
	}
	cout<<ans;
	return 0;
}
