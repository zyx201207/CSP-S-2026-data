#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,T,n,d,a[2000006],f[2000006],dp[2000006],dis[2000006],last,now,ans,maxn;
deque<int>ql,qr;
void sol(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>a[i];
	int l=1,r=4;                             
	for(int i=3;i<=n;i++){
		while(i+1<=n&&l<=n&&a[l]+d<a[i+1])ql.push_back(l++);
		while(r<=n&&a[r]-d<=a[i-1])qr.push_back(r++);
		while(!ql.empty()&&a[ql.front()]+d<a[i])ql.pop_front();
		while(!qr.empty()&&a[qr.front()]-d<=a[i-2])qr.pop_front();
		ans+=1ll*ql.size()*qr.size();
		//cout<<ql.front()<<" "<<ql.back()<<"&&";
		//cout<<qr.front()<<" "<<qr.back()<<endl;
	}
	cout<<ans<<"\n";
	ans=0;
	for(int i=1;i<=n;i++)f[i]=dp[i]=dis[i]=0;
	while(!ql.empty())ql.pop_front();
	while(!qr.empty())qr.pop_front();
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>T;
	while(T--)sol();
}
