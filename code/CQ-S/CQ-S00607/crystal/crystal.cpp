#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> Pair;
const int N=5e5+5;
int n,ans=0;;
ll m;
ll a[N],sum[N];
int erfen(int l,int r){
	ll x=a[r];
	int R=r;
	while(l<r){
		int mid=l+r+1>>1;
		if(x*(R-mid+1)-(sum[R]-sum[mid-1])<=m) r=mid-1;
		else l=mid;
	} 
	return l;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		int u=erfen(0,i);
		ans=max(ans,i-u);
	}
	cout<<ans;
	return 0;
} 
/*
Total 100+100+40+25=265
²»Òª¹Ò·Ö 
*/ 
