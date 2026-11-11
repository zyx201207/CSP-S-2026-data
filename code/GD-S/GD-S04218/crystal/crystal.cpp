#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m;
int a[N];
int sum[N];
bool check(int mid,int x){
	int dis=a[x]*(x-mid+1)-sum[x]+sum[mid-1];
	return dis<=m;
}
int maxn;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
		int l=0,r=i+1;
		while(l+1<r){
			int mid=(l+r)/2;
			if(check(mid,i))r=mid;
			else l=mid;
		}
		maxn=max(maxn,i-r+1);
	}
	cout<<maxn;
	return 0;
}

