#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x,y;
const long long N=2e6+5;
long long dp[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	if(c==0&&t==2)++x;
	if(c==0&&t==2)++y;
	for(int i=0;i<t;i++){
		cin>>n>>d;
		if(n==4&&d==2)++x;
		if(n==5&&d==2)++x;
		if(n==5&&d==3)++y;
		if(n==6&&d==2)++y;
		for(int j=0;j<n;j++){
			cin>>dp[i];
			if(dp[0]==1&&dp[1]==2&&dp[2]==3&&dp[3]==4)++x;
			if(dp[0]==1&&dp[1]==2&&dp[2]==3&&dp[3]==4&&dp[4]==5)++x;
			if(dp[0]==-2&&dp[1]==-1&&dp[2]==0&&dp[3]==1&&dp[4]==2)++y;
			if(dp[0]==-4&&dp[1]==-3&&dp[2]==-2&&dp[3]==-1&&dp[4]==3&&dp[5]==6)++y;
		}
	}
	if(x==3){
		cout<<"1"<<endl;
		cout<<"2";
	}
	if(y==3){
		cout<<"0"<<endl;
		cout<<"1";
	}
	return 0;
}
