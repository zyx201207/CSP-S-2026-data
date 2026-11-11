#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int p[35];
map<int,int>mp;
struct node{
	int b,q,p;
}a[200005];
int check(int x){
	int l=1,r=31;
	if(x==1){
		return 1;
	}
	while(l<r){
		int mid=(r-l)/2+l;
		if(p[mid]<x) l=mid+1;
		else r=mid;
	}
	if(p[l]==x) return l-1;
	return l;
}
bool cmp(node a,node b){
	if(a.p==b.p) return a.b>b.b;
	return a.p<b.p;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	p[0]=1;
	for(int i=1;i<=30;i++){
		p[i]=p[i-1]*2;
	}
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].b;
		mp[a[i].b]++;
		int q=check(a[i].b);
		a[i].q=q;
		a[i].p=p[q]-a[i].b;
	}
	sort(a+1,a+n+1,cmp);
	ans=a[1].b;
	for(int i=2;i<=m;i++){
		ans&=a[i].b;
	}
	for(auto v:mp){
		if(v.second>=2){
			ans=max(ans,v.first);
		}
	}
	cout<<ans;
	return 0;
}
