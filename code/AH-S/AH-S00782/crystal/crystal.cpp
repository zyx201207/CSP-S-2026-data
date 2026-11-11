#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll a[500005];
ll l,r;
ll ans,sum;
map<int,ll>mp;
void dfs(int id,int x){
	mp.clear();
	for(int i=1;i<=n;i++){
		mp[a[i]]++;
		ans=max(ans,mp[a[i]]);
//		cout<<a[i]<<" ";
	}
//	cout<<"\n";
	if(x==0)return ;
	if(id==n+1)return ;
	ll tmp=a[id];
	a[id]++;
	dfs(id+1,x-1);
	a[id]=tmp;
	dfs(id+1,x);
}
bool cmp(int x,int y){
	return abs(x-sum)<abs(y-sum);
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
		sum+=a[i];
	}
	sum=(sum)/n;
	sort(a+1,a+1+n,cmp);
//	for(int i=1;i<=n;i++){
//		cout<<a[i]<<" ";
//	}
	for(int i=1;i<=n;i++){
		if(m-abs(a[i]-sum)>=0){
			m-=abs(a[i]-sum);
			ans++;
		}else break;
	}
	cout<<ans;
	return 0;
} 
