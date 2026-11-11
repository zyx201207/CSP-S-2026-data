#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=2e6+5;

int n,pre[N],cnt[N],dis[N];
ll x[N],d;

void SolveA(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>x[i];
	int len=1;
	cnt[1]=1;
	pre[1]=1;
	dis[1]=0;
	dis[0]=-1;
	pre[0]=0;
	vector<int> vec;
	ll ans=0,smans=0;
	for(int i=2;i<=n;i++){
		len++;
		while(x[i]-x[i-len+1]>d)--len;
		if(len==1)break;
		dis[i]=dis[i-len+1]+1;
		if(dis[i-1]==dis[i-2])vec[int(vec.size())-1]=i-1;
		else vec.push_back(i-1);
		cnt[i]=min(pre[vec[dis[i-len+1]]]-pre[i-len],3);
//		cout<<s<<' '<<i<<' '<<cnt[i]<<'\n';
		pre[i]=pre[i-1]+cnt[i];
		if(cnt[i]==2)smans++;
		ans+=smans;
	}
	cout<<ans<<'\n';
	return;
}

void Solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>x[i];
	int ans=0;
	for(int s=1;s<=n;s++){
		int len=1;
		cnt[s]=1;
		pre[s]=1;
		dis[s]=0;
		dis[s-1]=-1;
		pre[s-1]=0;
		vector<int> vec;
		for(int i=s+1;i<=n;i++){
			len++;
			while(x[i]-x[i-len+1]>d)--len;
			if(len==1)break;
			dis[i]=dis[i-len+1]+1;
			if(dis[i-1]==dis[i-2])vec[int(vec.size())-1]=i-1;
			else vec.push_back(i-1);
			cnt[i]=min(pre[vec[dis[i-len+1]]]-pre[i-len],3);
//			cout<<s<<' '<<i<<' '<<cnt[i]<<'\n';
			pre[i]=pre[i-1]+cnt[i];
			if(cnt[i]==2)ans++;
		}
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c,t;
	cin>>c>>t;
	while(t--){
		if(c==11||c==12)SolveA();
		else Solve();
	}
	return 0;
}
/*
11 1
10 21
0 7 14 21 28 35 42 49 56 63
*/
