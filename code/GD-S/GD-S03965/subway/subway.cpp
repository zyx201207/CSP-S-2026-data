#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll w[500005];
ll dp[500005];
struct st{
	vector<ll> pre;
	ll time;
	ll id;
	vector<ll> next;
};
struct way{
	ll x,y;
};
map<int,st> mp;
way wa[100005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;//n 路线数，m 地铁站数，d 最多被路过，q 方案数 
	for(ll i=1;i<=m;i++){// 
		cin>>w[i];// 
	}// 
	for(ll i=1;i<=n;i++){
		ll k;
		cin>>k;
		ll a,t,pr;
		cin>>a>>t;// 
		mp[a].time=t;// 
		mp[a].id=a;// 
		pr=a;//第一次 
		for(ll j=2;j<k;j++){
			cin>>a>>t;
			mp[a].time=t;
			mp[a].id=a;
			mp[a].pre.push_back(mp[pr].id);
			mp[pr].next.push_back(mp[a].id);
			pr=a;
		}
		cin>>a>>t;// 
		mp[a].time=t;// 
		mp[a].id=a;// 
		mp[a].pre.push_back(mp[pr].id);
		mp[pr].next.push_back(mp[a].id);
		pr=a;//最后一次 
	}
//	for(int i=1;i<=m;i++){
//		cout<<mp[i].id<<endl;
//		for(int j=0;j<mp[i].pre.size();j++){
//			cout<<mp[i].pre[j]<<" ";
//		}
//		cout<<endl;
//		for(int k=0;k<mp[i].next.size();k++){
//			cout<<mp[i].next[k]<<" ";
//		}
//		cout<<endl;
//	}
	for(int i=1;i<=q;i++){
		cin>>wa[i].x>>wa[i].y;
	}
	for(int i=1;i<=m;i++){
		dp[i]=0;
	}
	for(int i=1;i<=q;i++){
		ll x1=wa[i].x;
		ll y1=wa[i].y;
		dp[x1]=mp[x1].time;
		if(x1>y1) swap(x1,y1);
		for(int j=x1+1;j<=y1;j++){
			for(int k=0;k<mp[j].pre.size();k++){
				if(mp[j].pre[k]<j) continue;
				dp[j]=min(mp[j].time+mp[mp[j].pre[k]].time+dp[j],mp[j].time+dp[j]);
			}
		}
		cout<<dp[y1-1]<<endl;
	}
	return 0;
}
//2////////////
//0 3 7 20 2
//8 3 6 1 7 2 9
//3 1 4 2 5 5 100
//3 2 6 3 1 7 2
//4 3 2 5 100 4 6 6 7
//1////////////
//0 2 5 20 2
//4 1 9 2 5
//3 1 5 2 7 4 6
//3 2 3 3 4 5 7

