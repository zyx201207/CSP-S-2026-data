#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll c,t,n,d,x[2000005],dp[2000005],sum[2000005];
vector<int> v;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		ll cnt=0;
		for(int st=1;st<=n;st++){
			memset(dp,0,sizeof(dp));
			memset(sum,0,sizeof(sum));
			dp[st]=sum[st]=1;
			v.clear();
			v.push_back(st);
			v.push_back(st);
			int lid=st;
			//cout<<sum[0]<<" "<<sum[1]<<"\n";
			for(int i=st+1;i<=n;i++){
				while(x[lid]<x[i]-d) lid++;
				if(x[v[v.size()-2]]<x[i]-d){
					v.push_back(i-1);
				}
				v[v.size()-1]++;
				dp[i]=sum[v[v.size()-2]]-sum[lid-1];
				if(lid==i) dp[i]=0;
				//cout<<i<<" "<<lid<<" "<<v[v.size()-2]<<" "<<dp[i]<<"\n";
				sum[i]=sum[i-1]+dp[i];
				if(dp[i]==2) cnt++;
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
} 
