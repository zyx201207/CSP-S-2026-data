#include<bits/stdc++.h>
using namespace std;
const int N=5e3+100;
long long c;
long long d;
long long a[N];
long long dp[N];
long long cnt=0;
long long ans=0;
vector<pair<long long,long long> > ids[N];
vector<pair<long long,long long> > e[2*N];
long long aaa,bbb;
long long ci[N];
void dij(long long st){
	memset(ci,0,sizeof(ci));
	bool vis[2*N]={0};
	long long d1[N]={0};
	priority_queue<pair<long long,long long>,vector<pair<long long,long long> >,greater<pair<long long,long long> >  > q;
	for(auto v:e[st]){
		if(vis[v.first]){
			continue;
		}else{
			q.push({v.second,v.first});
			vis[v.first]=1;
		}
	}
	vis[st]=1;
	while(!q.empty()){
		pair<long long,long long> nw=q.top();
		q.pop();
		
//	for(int i=1;i<=cnt;i++){
//		cout<<ci[i]<<" ";
//	}
//	cout<<"******\n";
		vis[nw.second]=1;
		ci[nw.second]=1;
		d1[nw.second]=nw.first;
		for(auto v:e[nw.second]){
			if(vis[v.first]){
				if(v.second==d1[v.first]){
					ci[v.first]++;
//					cout<<1<<"\n";
				}
				continue;
			}
			q.push({nw.first+v.second,v.first});
			vis[v.first]=1;
//			cout<<nw.second<<"-"<<v.first<<":"<<nw.first+v.second<<"\n";
		}
	}
//	for(int i=1;i<=cnt;i++){
//		cout<<d1[i]<<" ";
//	}
//	cout<<"\n";
//	for(int i=1;i<=cnt;i++){
//		cout<<ci[i]<<" ";
//	}
//	cout<<"\n";
	for(int i=1;i<=cnt;i++){
		if(ci[i]==2){
			ans++;
//			cout<<ans<<'\n';
		}
	}
}
void solve(){
	ans=0;
	set<pair<long long,long long> > s;
	cin>>cnt>>d;
	s.clear();
	for(int i=1;i<=cnt;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+cnt);
	for(long long i=1;i<=cnt;i++){
		for(long long j=i+1;j<=cnt;j++){
			if(abs(a[i]-a[j])<=d)
			s.insert({i,j});
		}
	}
	for(auto a:s){
		long long i=a.first,j=a.second;
		e[i].push_back({j,1});
		e[j].push_back({i,1});
	}
//	for(int i=1;i<=cnt;i++){
//		for(auto a:e[i]){
////			cout<<i<<"->"<<a.first<<":"<<a.second<<"\n";
//		}
//	}
	for(int i=1;i<=cnt;i++){
		dij(i);
//		cout<<i<<":"<<ans<<"\n";
	}
	cout<<ans<<"\n";
}
long long T;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		solve();
	}
	return 0;
} /*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5




*/
