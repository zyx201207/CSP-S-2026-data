//GZ-S00040 贵阳市第一中学 敖翔蓝天 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000005
queue<ll> q;
ll m,n,a[N],cnt=2,dqdz,sigz;
ll mx=1;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	q.push(a[1]);
	sigz=a[1];
	for(int i=2;i<=n;i++){
		while(dqdz+q.size()*(a[i]-sigz)>m&&q.size()){
			ll s=q.front();
			q.pop();
			dqdz-=a[i-1]-s;	
			
		}
		dqdz+=(a[i]-sigz)*q.size();
		sigz=a[i];
		q.push(a[i]);
		ll sz=q.size();
		mx=max(mx,sz);
	}
	cout<<mx;
	return 0;
}
