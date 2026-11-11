#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+3;
int n,l,r;
ll m,a[N],s[N];
bool chk(int x){
	for(int i=1;i+x-1<=n;i++)if(a[i+x-1]*x-s[i+x-1]+s[i-1]<=m)return 1;
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	l=1,r=n;
	while(l<r){
		int md=(l+r+1)/2;
		if(chk(md))l=md;
		else r=md-1;
	}
	cout<<l;
}
