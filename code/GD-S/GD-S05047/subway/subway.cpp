#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
vector<long long> w,dp[505];
long long smg[505][500005];
void aa(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=smg[i][0];j++){
			dp[i][j]=-1;
		}
	}
	for(int i=1;i<=n;i++){
		int fl=0;
		for(int j=1;j<=smg[i][0];j++){
			if(smg[i][j]!=0&&smg[i-1][j]!=-1){
				dp[i][j]=dp[i-1][j]+smg[i-1][j]+smg[i][j];
				fl=dp[i][j];
			}else if(smg[i][j]!=0){
				dp[i][j]=fl;
			}else{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
}
int main(){
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		int k;
		cin>>k;
		w.push_back(k);
	}
	for(int i=1;i<=n;i++){
		int kw;
		cin>>kw;
		smg[i][0]=kw;
		for(int j=1;j<=kw;j++){
			int a,t;
			cin>>a>>t;
			smg[i][a]=t;
		}
	}
	aa();
	while(q--){
		int ans=0;
		int st,ed;
		cin>>st>>ed;
		ans+=w[st];
		
	}
	return 0;
} 
