#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=5e5+1;
int n,m,ans;
int a[N],q[N];

bool check(int x,int l){
	int sum=(x-l+1)*a[x]-q[x]+q[l-1];
	if(sum>m) return 0;
	else return 1;
}

int Erfen(int l,int r,int s){
	if(l>r) return r;
	int mid=(l+r)>>1;
	if(check(mid,s)) Erfen(mid+1,r,s);
	else Erfen(l,mid-1,s);
}

void solve(){
	for(int i=1;i<=n;i++) ans=max(ans,Erfen(i,n,i)-i+1);
	cout<<ans;
	return;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) q[i]=q[i-1]+a[i];
	solve();
	return 0;
}

/*
in:
5 5
1 2 4 8 9
1 3 7 15 24
out:
3

in:
5 8
-3 -1 2 2 7
out:
4

*/