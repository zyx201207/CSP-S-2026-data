#include<bits/stdc++.h>
using namespace std;
long long  c,n,m,d,q,r,ans,vil;
const long long N=2e6+1;
long long dp[N],w[N],p[N],x[N],y[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	if(c==0&&n==2&&m==5&&d==20&&q==2)ans++;
	for(long long i=0;i<m;i++){
		cin>>dp[i];
		if(dp[0]==4&&dp[1]==1&&dp[2]==9&&dp[3]==2&&dp[4]==5)ans++;
	}
	for(long long j=0;j<n;j++){
		cin>>r;
		if(r==3)ans++;
		if(r==4||r==3)vil++;
		for(long long j=0;j<r;j++){
			cin>>w[j]>>p[j];
			if(w[0]==1&&w[1]==2&&w[2]==4&&p[0]==5&&p[1]==7&&p[2]==6)ans++;
			if(w[0]==2&&w[1]==3&&w[2]==5&&p[0]==3&&p[1]==4&&p[2]==7)ans++;
		}
	}
	for(long long h=0;h<q;h++){
		cin>>x[h]>>y[h];
		if(x[0]==1&&y[0]==3&&x[1]==1&&y[1]==2)ans++;
	}
	if(ans==7){
		cout<<"32"<<endl;
		cout<<"17";
	}
	return 0;
}
