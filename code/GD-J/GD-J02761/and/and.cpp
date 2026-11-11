#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=300005;
ll n,m,ans=-1;
ll a[maxn];
ll search(ll,ll,ll);
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	ans=search(1,0,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
}
ll search(ll i,ll c,ll now){
//	printf("search(%d,%d,%d);\n",i,c,now);
	if(c==m)return now;
	if(i>n)return 0;
	//如果要选第i个数
	ll e;
	if(c==0) e=a[i];
	else e=now&a[i];
	ll r=search(i+1,c+1,e);
	//如果不选第i个数
	ll d=search(i+1,c,now); 
	now=max(d,r);
	return now;
}
