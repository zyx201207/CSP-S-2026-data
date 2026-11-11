#include<bits/stdc++.h>
using namespace std;
long long n,c,t,d;
long long a[2000005];
bool f1=1;
long long xza;
long long ans[2000005];
long long dis[2000005];
bool check(long long i,long long j){
	for(int i=1;i <= n;i++){
		ans[i]=0;
		dis[i]=n+1;
	}
	priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> q;
	q.push({0,i});
	while(!q.empty()){
		auto x=q.top();
		if(x.first<dis[x.second]){
			dis[x.second]=x.first;
			ans[x.second]=0;
		}
		if(x.first==dis[x.second]){
			ans[x.second]++;
		}
		q.pop();
		long long next=x.second+1;
		long long s=x.second;
		while(next<=j&&(a[next]-a[s])<=d){
			q.push({x.first+1,next});
			next++;
		}
	}
	if(ans[j]==2){
		return 1;
	}
	return 0;
} 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	
	while(t--){
		cin >> n >> d;
		f1=true;
		for(int i=1;i <= n;i++){
			cin >> a[i];
			if(i>=3){
				if(a[i]-a[i-1]!=xza){
					f1=false;
				} 
			}
			else{
				xza=a[i]-a[i-1];
			}
		}
		if(n<=2){
			cout << 0 << endl;
			continue;
		}
		long long ans=0;
		for(int i=1;i <= n;i++){
			for(int j=i+2;j <= n;j++){
				if(check(i,j)){
					ans++;
				}
			}
		}
		cout << ans << endl;
	} 
	return 0;
} 
