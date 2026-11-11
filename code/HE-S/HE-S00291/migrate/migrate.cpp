#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=2e6+100;
ll c,t,n,d,x[N],ans=0,u,sum[N],cnt[N],pann[N],cha,A=0;
queue <ll> q,len;
vector <ll> s[N];

void bfs(){
	while(!q.empty()){
		u=q.front();
		for(ll i=0;i<s[u].size();i++){
			sum[s[u][i]]=min(sum[s[u][i]],len.front()+1);
			q.push(s[u][i]);
			len.push(len.front()+1);
		}
		q.pop();
		len.pop();
	}
	while(!q.empty()){
		q.pop();
	}
	while(!len.empty()){
		len.pop();
	}
	return;
}

void pan(){
	while(!q.empty()){
		u=q.front();
		for(ll i=0;i<s[u].size();i++){
			cnt[s[u][i]]=len.front()+1;
			if(cnt[s[u][i]]==sum[s[u][i]]){
				pann[s[u][i]]++;
			}
			q.push(s[u][i]);
			len.push(len.front()+1);
		}
		q.pop();
		len.pop();
	}
	while(!q.empty()){
		q.pop();
	}
	while(!len.empty()){
		len.pop();
	}
	return;
}

void solve(){
	ans=0;
	cin>>n>>d;
	for(ll i=1;i<=n;i++){
		cin>>x[i];
	}
	cha=x[2]-x[1];
	for(ll i=2;i<=n;i++){
		if(cha!=x[i]-x[i-1]){
			A=1;
		}
	}
	if(A==0){
		ans=0;
		ll ga=d/cha;
		for(ll i=ga+2;i<=n;i++){
			ans++;
		}
		ans=min(ans,ga-1);
		cout<<ans<<'\n';
		return;
	}
	for(ll i=1;i<=n;i++){
		for(ll j=i+1;j<=n;j++){
			if(x[j]-x[i]<=d){
				s[i].push_back(j);
			}
		}
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			sum[j]=9999999999;
		}
		q.push(i);
		len.push(0);
		bfs();
		for(ll j=1;j<=n;j++){
			cnt[j]=9999999999;
			pann[j]=0;
		}
		q.push(i);
		len.push(0);
		pan();
		for(ll j=1;j<=n;j++){
			if(pann[j]==2){
				ans++;
			}
		}
	}
	cout<<ans<<'\n';
	for(ll i=1;i<=n;i++){
		s[i].clear();
	}
	return;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}
