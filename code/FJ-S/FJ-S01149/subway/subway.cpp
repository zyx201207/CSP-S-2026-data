#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,n,m,d,q;
int ans=0;
int e[510][510];
int dp[510][510];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	vector<int> w(n+5,0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i){
		cin>>w[i];
	}
	vector<int> a[n+3],t[n+3];
	vector<int> k(n+3,0);
	int tmp1,tmp2;
	for(int i=1;i<=n;++i){
		cin>>k[i];
		for(int j=1;j<=k[i];++j){
			cin>>tmp1>>tmp2;
			a[i].push_back(tmp1);
			t[i].push_back(tmp2);
		}
		for(int j=0;j<k[i]-1;++j){
			int u=t[i][j]+t[i][j+1];
			//cout<<a[i][j]<<" "<<a[i][j+1]<<" "<<u<<endl;
			//WHO ARE YOU
			e[a[i][j]][a[i][j+1]]=u;
			e[a[i][j+1]][a[i][j]]=u;
		}
	}
	for(int i=0;i<=500;++i){
		for(int j=0;j<=500;++j){
			if(e[i][j]||i==j)dp[i][j]=e[i][j];
			else dp[i][j]=0x3f3f3f3f;
		}
	}
	for(int i=1;i<=m;++i){
		for(int j=1;j<=m;++j){	  //cout<<"i and j :"<<i<<" "<<j<<endl;
			if(i==j)dp[i][j]=0;
			else
			{
				for(int k=1;k<=m;++k){//cout<<"\tk:"<<k<<endl;
									  //cout<<"\tdp[i][j]         :"<<dp[i][j]<<endl;
									  //cout<<"\tdp[i][k]+dp[k][j]:"<<dp[i][k]+dp[k][j]<<endl;
					dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
									  //cout<<"\tnew dp[i][j]     :"<<dp[i][j]<<endl;
	
				}
			}
		}
	}
	int x,y;//cout<<q<<endl;
	for(int i=1;i<=q;++i){
		//cout<<"i:"<<i<<endl;
		cin>>x>>y;//cout<<x<<" "<<y<<"dp[x][y]:"<<dp[x][y]<<endl;
		//cout<<x<<" "<<y<<endl;
		cout<<dp[x][y]+w[x]+w[y]<<endl;
	}
	
	return 0;
}

