#include<bits/stdc++.h>
#define int long long
#define stp(x) fixed<<setprecision(x)
using namespace std;
const int N=5e5+10;
int n,m;
int a[N];
inline bool chk(int x){
	int s=0;
	for(int i=1;i<x;i++)s+=a[i];
	for(int i=x;i<=n;i++){
		s=s-a[i-x]+a[i];
		if(a[i]*x-s<=m)return true;
	}
	return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	a[0]=0;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int L=0,R=n+1;
	while(L+1<R){
		int M=(L+R)>>1;
		if(chk(M))L=M;
		else R=M;
	}
	cout<<L<<"\n";
	return 0;
}
