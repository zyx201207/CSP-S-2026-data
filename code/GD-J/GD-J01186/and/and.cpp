#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
typedef long long ll;
int n,m;
ll a[N];
void solve1(){
	ll ma=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(a[i],ma);
	}
	cout<<ma;
}
void solve2(){
	ll b,ans=1;
	for(int i=1;i<=n;i++){
		cin>>b;
		ans&=b;
	}
	cout<<ans;
}
void solve3(){
	ll ans=1,ma=-1;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
			ma=max(ma,a[i]&a[j]);
	cout<<ma;
}/*
void solve4(){
	ll ma=-1;
	ll anf[N],ane[N];
	anf[0]=anf[n+1]=1;
	for(int i=1;i<=n;i++)
		cin>>a[i],anf[i]=anf[i-1]&a[i];
	for(int i=n;i>0;i--)
		ane[i]=ane[i+1]&a[i];
	for(int i=1;i<=n;i++)
		ma=max(ma,ane[i+1]&anf[i-1]);
	cout<<ma;
}*/
ll solve(int l,int k){
	ll ma=-1,g;
	for(int i=l;i<=n-k+1;i++){
		g=solve(i+1,k-1);
		g&=a[i];
		ma=max(ma,g);
	}
	return ma;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	if(n<=2000&&m==1) solve1();
	else if(n<=2000&&m==n) solve2();
	else if(n<=2000&&m==2) solve3();
//	if(m==n-1) solve4();
	else{
		for(int i=1;i<=n;i++)
			cin>>a[i];
		cout<<solve(1,m);
	}
	return 0;
}

