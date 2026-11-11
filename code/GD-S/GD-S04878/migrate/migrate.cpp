#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+5;
ll q[N],sum[N],sum1[N]; 
ll x[N];
ll c,t,n,d;
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	memset(q,0,sizeof q);
	memset(sum,0,sizeof sum);
	memset(sum1,0,sizeof sum1);
	int p=1;
	ll ans=0;
	for(int i=2;i<=n;i++){
		while(x[i]-x[p]>d) p++;
		q[i]=i-p;
		if(q[i]==1){
			sum[i]+=sum[i-1];
			sum1[i]+=sum1[i-1]+1;
			ans+=sum[i];
		}
		if(q[i]==2){
			if(q[i-2]==1&&q[i-1]==2){
				sum[i]+=sum1[i-2];
				sum1[i]+=sum1[i-2]+1;
			}
			if(q[i-2]==1&&q[i-1]==1){
				sum[i]+=sum[i-2];
				sum1[i]+=sum1[i-q[i]]+1;
			}
			if(q[i-1]==2&&q[i-2]==2){
				if(q[i-3]>1) sum[i]+=sum1[i-3]+1;
				else sum[i]+=1;
			}
			
			ans+=sum[i];
		}
		if(q[i]>2){
			if(q[i-q[i]]==1&&q[i-q[i]+1]==2&&q[i-q[i]+2]!=3){
				sum[i]+=sum1[i-q[i]];
				sum1[i]+=sum1[i-q[i]]+1;
			}
			else if(q[i-q[i]+1]>=q[i-q[i]+2]){
				for(int j=i-q[i]+1-q[i-q[i]+1];j<i-q[i]+2-q[i-q[i]+2];j++){
					if(q[j]>j-(i-q[i]-q[i-q[i]]))sum[i]+=sum1[j]+1;
					else sum[i]+=1;
				}
			}
			if(q[i-q[i]]==1&&q[i-q[i]+1]==1){
				sum[i]+=sum[i-q[i]];
				sum1[i]+=sum1[i-q[i]]+1;
			}
			
			ans+=sum[i];
		}
		//cout<<sum[i]<<" "<<sum1[i]<<endl;
	}
	cout<<ans<<endl;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>c>>t;
	while(t--) solve();
}
