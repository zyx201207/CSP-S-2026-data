#include <bits/stdc++.h>
using namespace std;
long long x[2000005];
vector<long long> vec[5005];
long long dis[5005],cnt[5005];
void bfs(long long s){
	dis[s]=0;
	queue<long long> q;
	q.push(s);
	while(!q.empty()){
		long long u=q.front();
		q.pop();
		for(long long v:vec[u]){
			if(dis[v]>=dis[u]+1){
				cnt[v]++;
				dis[v]=dis[u]+1;
				q.push(v);
			}
		}
	}
}
void work1(){
	long long t;
	cin>>t;
	while(t--){
		long long n,d;
		cin>>n>>d;
		for(long long i=1;i<=n;i++){
			cin>>x[i];
			vec[i].clear();
		}
		for(long long i=1;i<=n;i++){
			for(long long j=i+1;j<=n;j++){
				if(x[j]-x[i]<=d){
					vec[i].push_back(j);
					vec[j].push_back(i);
				}
			}
		}
		long long ans=0;
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=n;j++){
				dis[j]=0x3f3f3f3f3f3f3f3f;
				cnt[j]=0;
			}
			bfs(i);
			for(long long j=1;j<=n;j++){
				//cout<<i<<" "<<j<<" "<<cnt[j]<<" "<<dis[j]<<endl;
				if(cnt[j]==2){
					ans++;
				}
			}
		}
		cout<<ans/2<<endl;
	}
}
void work2(){
	int t;
	cin>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		int ans=n*n;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1,l=1,r=1;i<=n;i++){
			while(x[i]-x[l]>d)l++;
			while(x[r+1]-x[i]<=d)r++;
			ans-=(r-l+1);
		}
		cout<<ans<<endl;
	}
	
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c;
	cin>>c;
	if(c<=10)work1();
	else if(c==13||c==14)work2();
}
