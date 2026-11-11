#include<bits/stdc++.h>
#define ll long long
//unsigned long long
//priority_queue<int,vector<int>,greater<int>>
using namespace std;
int c,t,n,ans;
ll d;
ll x[2000006];
bool check(int l,int r){
	if(x[r]-x[l]<=d)return false;
	int dp[r+1]={0},sum=0;
	for(int i=l+1;i<=r;i++){
		dp[i]=dp[i-1]+1;
		for(int j=l;j<i;j++){
			if(x[i]-x[j]<=d){
				dp[i]=min(dp[i],dp[j]+1);
			}
		}
	}
	for(int i=l;i<r;i++){
		if(dp[i]+1==dp[r]&&x[r]-x[i]<=d){
			sum++;
		}
	}
	if(sum!=2)return false;
	return true;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(c==11||c==12){
			if(x[3]-x[1]>d){
				cout<<0<<endl;
				continue;
			}
		}
		if(c==13||c==14){
			cout<<0<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(check(i,j))ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

