#include<bits/stdc++.h>
using namespace std;
int dp[200005][2]={},n,m,a[200005],MMM=INT_MIN;
bool l[200005]={};
void dfs(int xxx,int shi){
	if(xxx==0){
		MMM=max(shi,MMM);
		return;
	}
	for(int i=1;i<=n;i++){
		if(l[i]==0){
			l[i]=1;
			dfs(xxx-1,(shi&a[i]));
			l[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		MMM=max(MMM,a[i]);
	}if(m==1){
		cout<<MMM;
		return 0;
	}int g2=0,_2=1;
	vector<int>vv;
	for(int i=0;i<30;i++){
		g2+=_2;
		_2*=2;
		vv.push_back(_2);
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<30;j++){
			if(vv[j]==a[i]+1)goto E;
		}goto W;
		E:;
	}cout<<MMM;
	return 0;
	W:
	MMM=INT_MIN;
	dfs(m,g2);
	cout<<MMM;
//	dp[1][0]=a[1];
//	for(int i=2;i<=n;i++){
//		dp[i][1]=max((dp[i-1][0]&a[i]),(dp[i-1][1]&a[i]));
//		dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
//	}cout<<max(dp[n][0],dp[n][1]);
}
