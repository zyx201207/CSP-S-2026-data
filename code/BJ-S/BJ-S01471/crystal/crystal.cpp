#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll c[N],a[N];
ll n,m;
int lowbit(int x){
	return x&-x;
}
void add(int x,ll v){
	for(int i=x;i<=n;i+=lowbit(i))c[i]+=v;
}
ll ask(int x){
	ll res=0;
	for(int i=x;i>0;i-=lowbit(i))res+=c[i];
	return res;
}
bool check(int mid,int i){
	ll res=(i-mid+1)*a[i]-(ask(i)-ask(mid-1));
	return res<=m;
}
int erf(int x){
	int l=1,r=n;
	while(l<r){
		int mid=(l+r)/2;
		if(check(mid,x))r=mid;
		else l=mid+1;
	}
	return l;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)add(i,a[i]);
	int ans=1;
	for(int i=1;i<=n;i++){
		int k=erf(i);
		ans=max(ans,i-k+1);
	}
	cout<<ans;
	return 0;
}
