#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long n,l;
long long a[2000005];
struct node{
	long long lo,sum;
};
void solve(){
	cin>>n>>l;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(l>=a[n]-a[1]){
		cout<<0<<endl;
		return;
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		for(int j=4;j<=n;j++){
			long long ss=1e18,sums=0;
			queue<node> q;
			q.push({i,0});
			while(!q.empty()){
				node x=q.front();
				q.pop();
				long long lo=x.lo;
				long long sum=x.sum;
				if(sum+1>ss) continue;
				long long next;
				long long lo_s=a[lo]+l;
				next=upper_bound(a+1+i,a+1+j,lo_s)-a-1;
				if(next==j&&lo_s<a[j]) next--;
				if(next==j){
					if(ss==sum+1) sums++;
					else if(ss>sum+1){
						ss=sum+1;
						sums=1;
					}
					continue;
				}
				for(int xx=lo+1;xx<=next;xx++){
					q.push({xx,sum+1});
				}
			}
			if(sums==2) ans++;
		}
	}
	cout<<ans<<endl;
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}