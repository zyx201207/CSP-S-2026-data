#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
struct node{
	int a,b;
}t[500010];
bool cmp(node a,node b){
	return a.a<b.a;
}
bool check(int mid){
	for(int i=mid;i<=n;i++){
		if(t[i].b-(i-mid)*(t[i].a-t[i-mid].a)-t[i-mid].b<=m)return true;
	}
	return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >>n>>m;
	for(int i=1;i<=n;i++)cin >>t[i].a;
	sort(t+1,t+n+1,cmp);
	for(int i=1;i<=n;i++)t[i].b=(i-1)*(t[i].a-t[i-1].a)+t[i-1].b;
	int l=1,r=n;
	while(l<r){
		int mid=(l+r+1)/2;
		if(check(mid))l=mid;
		else r=mid-1;
	}
	cout <<l;
	return 0;
}
