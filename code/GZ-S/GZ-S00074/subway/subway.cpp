//GZ-S00074 ³ÂèªÄÏ 
#include<bits/stdc++.h>
using namespace std;
long long w[1000010],temp1[1000010],temp2[1000010],dp[3010][3010],p;
map<long long,long long> mp;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>temp1[j]>>temp2[j];
		}
		for(int j=1;j<=k;j++){
			for(int o=j+1;o<=k;o++){
				if(mp[temp1[j]]==0){
					p++;
					mp[temp1[j]]=p;
				}
				if(mp[temp1[o]]==0){
					p++;
					mp[temp1[o]]=p;
				}
				dp[mp[temp1[j]]][mp[temp1[o]]]=temp2[j]+temp2[o];
				dp[mp[temp1[o]]][mp[temp1[j]]]=temp2[j]+temp2[o];
			}
		}
	}
	for(int i=1;i<=500;i++){
		for(int j=1;j<=500;j++){
			if(dp[i][j]==0){
				dp[i][j]=INT_MAX;
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			for(int k=1;k<=m;k++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<dp[mp[x]][mp[y]]+w[mp[x]]+w[mp[y]]<<endl;
	}
	return 0;
}
