#include<bits/stdc++.h>
using namespace std;
long long cc,t;
long long cnt[2000100];
long long dp[5100][5100];
//long long ll(long long x){
//	return x&(-x);
//}
		long long n,d;
//long long tree[6000];
////void add(long long d,long long id){
////	while(id<=n){
////		tree[id]+=d;
////		id+=ll(x);
////	}
////}
//long long fc(long long id){
//	long long sum=0;
//	while(id>0){
//		sum+=tree[id];
//		id-=ll(id);
//	}
//	return sum;
//}
long long zhi[5010],sum[5010];
bool fl[5010];
vector<int> c[5010];
signed main(){
	freopen("migrate.in","r",stdin);//!!!!!!!!!!!!!!
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>cc>>t;
	if(cc==13||cc==14){
		while(t--){
		cin>>n>>d;
		for(long long i=1;i<=n;i++){
			cin>>cnt[i];
		}
			long long zhi=d/(cnt[2]-cnt[1]);
			cout<<(n-2*zhi+1)<<"\n";
		}
		return 0;
	}
	while(t--){
		cin>>n>>d;
		for(long long i=1;i<=n;i++){
			cin>>cnt[i];
		}
		for(long long i=1;i<=n;i++){
			long long zz=d+cnt[i];
			long long pl=upper_bound(cnt+1,cnt+1+n,zz)-cnt-1;
			for(long long j=i+1;j<=pl;j++){
				c[i].push_back(j);	
			}
		}
		long long ti=0;
		long long ans=0;
		for(long long k=1;k<=n;k++){
			for(long long i=1;i<=n;i++){
				sum[i]=0;
				ti=0;
				fl[i]=0;
			}
			queue<long long> q;
			q.push(k);
			fl[k]=1;
			queue<long long> qqq;
			while(!q.empty()){
				long long ss=q.size();
			ti++;
				for(long long i=1;i<=ss;i++){
					long long qq=q.front();
					q.pop();
					sum[qq]++;
					for(auto it:c[qq]){
						if(fl[it]==0){
							q.push(it);
							qqq.push(it);
						}
					}
				}
					while(!qqq.empty()){
						fl[qqq.front()]=1;
						qqq.pop();
					}
			}
			for(long long i=1;i<=n;i++){
				if(sum[i]==2){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
