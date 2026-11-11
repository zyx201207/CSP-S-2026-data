#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T,n,d,x[1000005],dp[5005][5005],jc[5005];
int js(vector<int>vp){
	int npos=1;
	int ccnt=0;
	for(int i=0;i<vp.size();i++){
		jc[i]=0;
		for(int j=i+1;j<vp.size();j++){
			dp[i][j]=0;
		}
	}
	for(int i=0;i<vp.size();i++){
		int j=i+1;
		while(j<vp.size()&&x[vp[j]]-x[vp[i]]<=d){
			dp[i][j]=1;
			j++;
			if(j==vp.size())break;
		}
		jc[i]=j;
	}
	for(int i=0;i<vp.size();i++){
		for(int j=jc[i];j<vp.size();j++){
			for(int k=i+1;k<=j-1;k++){
				dp[i][j]=max(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
		for(int j=jc[i];j<vp.size();j++){
			int cnt=0;
			for(int k=i+1;k<=j-1;k++){
				if(dp[i][j]==dp[i][k]+dp[k][j]){
					cnt++;
				}
			}
			if(cnt==2)ccnt++;
		}
	}
	return ccnt;
}
signed main(){
  	freopen("migrate.in","r",stdin);
  	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		vector<int>v[n+1];
		int cnt=1;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			if(i==1)v[cnt].push_back(i);
			else {
				if(x[i]-x[i-1]<=d)v[cnt].push_back(i);
				else{
					cnt++;
					v[cnt].push_back(i);
				}
			}
		}
		int ans=0;
		for(int i=1;i<=cnt;i++){
			ans+=js(v[i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}

