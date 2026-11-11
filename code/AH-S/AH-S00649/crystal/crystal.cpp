#include<iostream>
#include<algorithm>
#include<cmath>
#include<map>
#include<cstring>
using namespace std;
typedef long long ll;
ll a[500005],d[500005];
ll cnt[500005];
bool vis[500005];
ll n,m,f=0;
ll maxn,minn;
void solve1(){
	ll x,t=0,s=m;
	if(n%2==0) x=(a[n/2+1]+a[n/2])/2;
	else x=a[n/2]+1;
	int l=n/2,r=n/2+1;
	for(int i=n;i>=1;i--){
		if(s<0) break;
		s-=(a[n]-a[i]);
		++t;
	}
	cout<<t;
}
int find(int l,int r,ll x){
	while(l<r){
		ll mid=(l+r)/2;
		if(a[mid]>=x) r=mid;
		else l=mid+1;
	}
	return l;
}
void try2(){
	int x,t=0,s=m;
	if(n%2) x=a[n/2+1];
	else x=(a[n/2]+a[n/2+1])/2;
	for(int i=n/2;i>=1;i--){
		s-=(x-a[i]);
		if(s>0) t++; 
		else break;
	}
	cout<<t;
}
void try1(){
	int x;
	if(n%2) x=a[n/2+1];
	else x=(a[n/2]+a[n/2+1])/2;
	int p=find(1,n+1,x);
	x=a[p];
	ll t=0,s=m;
	for(int i=p;i>=1;i--){
		s-=(x-a[i]);
		if(s>0) t++;
		else break; 
	}
	cout<<t;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	ll k,f=0;
	ll avg=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		avg+=a[i];
		d[i]=a[i]-a[i-1];
	}
	if(n==1){
		cout<<1;
		return 0;
	}
	avg/=n;
	sort(a+1,a+n+1);
	maxn=a[n],minn=a[1];
	k=a[2]-a[1];
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=k) f=1; 
	}
	if(f==0) solve1();
	else try1();
	return 0;
}
