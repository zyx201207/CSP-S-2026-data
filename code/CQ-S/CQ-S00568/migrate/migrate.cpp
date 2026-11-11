#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=2e6+5;
int n,ls[N],rs[N]; 
ll d,A[N],num[N][2],sum[N][2];
void work(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>A[i];
	for(int i=1;i<=n;i++){
		ls[i]=lower_bound(A+1,A+n+1,A[i]-d)-A;
		rs[i]=upper_bound(A+1,A+n+1,A[i]+d)-A-1;
		if(ls[i]==i)ls[i]=0;
		else num[ls[i]][1]++;
		if(rs[i]==i)rs[i]=0;
		else num[rs[i]][0]++;
	}
	for(int i=1;i<=n;i++){
		sum[i][0]=num[i][0];
		sum[i][1]=num[i][1];
	}
	ll ans=0;
//	for(int i=1;i<=n;i++)cerr<<setw(2)<<A[i]<<" ";cerr<<"\n";
//	for(int i=1;i<=n;i++)cerr<<setw(2)<<num[i][0]<<" ";cerr<<"\n";
//	for(int i=1;i<=n;i++)cerr<<setw(2)<<num[i][1]<<" ";cerr<<"\n";
	for(int i=1;i<=n;i++)if(rs[ls[i]]==i)sum[i][0]+=sum[ls[i]][0];
	for(int i=n;i>=1;i--)if(ls[rs[i]]==i)sum[i][1]+=sum[rs[i]][1];
//	for(int i=1;i<=n;i++)cerr<<setw(2)<<sum[i][0]<<" ";cerr<<"\n";
//	for(int i=1;i<=n;i++)cerr<<setw(2)<<sum[i][1]<<" ";cerr<<"\n";
	for(int i=1;i<n;i++){
		if(!ls[i])continue;
		if(!rs[i+1])continue;
		if(rs[i]==i+1)continue;
		if(ls[i+1]==i)continue;
		ll a=(ls[i]==ls[i+1])?sum[i+1][0]:num[i+1][0];
		ll b=(rs[i]==rs[i+1])?sum[i][1]:num[i][1];
		ans+=a*b;
	}
	cout<<ans<<"\n";
	for(int i=1;i<=n+1;i++){
		num[i][0]=num[i][1]=0;
		A[i]=ls[i]=rs[i]=0;
	}
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	int c,t;
	cin>>c>>t;
	while(t--){
		work();
	}
	
	return 0;
} 
/*
0 1
10 22
0 7 14 21 28 35 42 49 56 63

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
