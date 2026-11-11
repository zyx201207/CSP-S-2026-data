#include<bits/stdc++.h>
using namespace std;
long long w[500005];
struct node{
	long long num;
	long long t;
}dp[500005][505];
struct plan{
	int s,d;
}p[100005];
int main(){
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	int c/*没用*/,n,m,d/*没用*/,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=n;j++){
			cin>>dp[j][i].num>>dp[j][i].t;
		}
	}
	cin>>q;
	for(int i=1;i<=q;i++){
		cin>>p[i].s>>p[i].d;
	}
	for(int i=1;i<=q;i++){
		int ans=0;
		
	}
	return 0;
}
