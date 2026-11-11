#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+10;
int n;
ll m,a[N],sum,tag,ans=1;
priority_queue<ll> q;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	//freopen("crystal4.in","r",stdin);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		ll now=a[i]-a[i-1];
		while(sum+now*(ll)q.size()>m&&!q.empty()){
			sum-=q.top()+tag;
			q.pop();
		}
		sum+=now*(ll)q.size();
		//cout<<tag<<' '<<now<<" "<<sum<<endl;
		tag+=a[i]-a[i-1];
		if(sum+now<=m){
			sum+=now;
			q.push(now-tag);
		}else if(!q.empty()&&q.top()>now){
			sum-=q.top()+tag;
			q.pop();
			sum+=now;
			q.push(now-tag);
		}
		//cout<<(ll)q.size()+1ll<<endl;
		ans=max(ans,(ll)q.size()+1ll);
	}
	cout<<ans;
	return 0;
}
