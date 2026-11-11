#include <bits/stdc++.h> 
using namespace std;
int T,n;
long long ans,d,zb[2000005];
long long dp[2000005][3];
int wz[2000005];
queue<int> dl;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>T>>T;
	while(T--){
		cin>>n>>d;ans=0;
		for(int i=1;i<=n;i++){
			cin>>zb[i];dp[i][0]=dp[i][1]=dp[i][2]=0,wz[i]=i;
		}
		while(!dl.empty())dl.pop();
		for(int i=n;i>=1;i--){
			while(!dl.empty()){
				if(zb[dl.front()]-zb[i]>d)dl.pop();
				else break;
			}
			if(!dl.empty())wz[i]=dl.front();
			dl.push(i);
		}
		//for(int i=1;i<=n;i++)cout<<wz[i]<<' ';
		//cout<<"*\n";
		for(int i=n;i>=2;i--){
			if(wz[i]==i)continue;
			if(wz[i-1]>=i)dp[i][0]=wz[i-1]-max(i,wz[i-2]);
			if(wz[i]>wz[i-1])dp[i][2]=wz[i]-max(i,wz[i-1]);
			if(wz[i]==wz[i-1]){
				if(wz[i-2]!=wz[i])dp[i][0]+=dp[wz[i]][2];
			}
			else{
				if(wz[i]==i+1||wz[i-1]+1<wz[i])dp[i][0]+=dp[wz[i]][0];
				else dp[i][0]+=dp[wz[i]][1];
			}
			if(wz[i]!=wz[i-1]){
				if(wz[i]==i+1||wz[i-1]+1<wz[i])dp[i][1]+=dp[wz[i]][0];
				else dp[i][1]+=dp[wz[i]][1];
			}
			if(wz[i]!=wz[i-1])dp[i][2]+=dp[wz[i]][2];
		}
		//for(int j=0;j<=2;j++){
		//	for(int i=1;i<=n;i++)cout<<dp[i][j]<<' ';
		//	cout<<":\n";
		//}
		for(int i=1;i<=n;i++){
			if(wz[i]!=i)ans+=dp[wz[i]][0];
		}
		cout<<ans<<'\n';
	}
	return 0;
}
