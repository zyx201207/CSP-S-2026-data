#include<bits/stdc++.h>//大样例过不了 
using namespace std;
struct data{
	int a,cnt;
}x[200005];
int dp[200005];
bool cmp(data p,data q){
	if(p.cnt==q.cnt){
		return p.a>q.a;
	}
	else return p.cnt>q.cnt;
}
int qpow(int e){
	int iii=0;
	while(e){
		if(e%2==1) iii++;
		e/=2; 
	}
	return iii;
}
int main(){
	freopen("and3.in","r",stdin);
	freopen("and3.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x[i].a;
		x[i].cnt=qpow(x[i].a);
	}
	sort(x+1,x+n+1,cmp);
	int ans=x[n].a;
	bool vis[200005]={};
	vis[n]=1;
	m-=1;
	while(m){
		int maxx=-1,wei=-1;
		for(int i=1;i<n;i++){
			dp[i]=(ans&x[i].a);
			if(dp[i]>maxx&&vis[i]==0){
				maxx=dp[i];
				wei=i;
			}
		}
		ans=maxx;
		vis[wei]=1;
		m-=1;
	}
	cout<<ans;
	return 0;
}
