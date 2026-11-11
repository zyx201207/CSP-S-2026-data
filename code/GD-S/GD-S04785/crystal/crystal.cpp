#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 5e5+10;
int arr[N],gong[N];

int n,ans;
int m;
bool check(int l,int r){
	return (gong[r]-gong[l-1]+m)>=(arr[r]*(r-l+1));
}

int tar(int x){
	int l=x,r=n,mid;
	while(l<r){
		mid=(l+r)>>1;
		if(l==mid)	mid++;
		if(check(x,mid)){
			l=mid;
		}else{
			r=mid-1;
		}
	}
	return l;
}

signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin >> n >> m;
	
	for(int i=1;i<=n;i++){
		cin >> arr[i];
	}
	sort(arr+1,arr+1+n);
	for(int i=1;i<=n;i++){
		gong[i]=gong[i-1]+arr[i];
	}
	
	for(int i=1;i<=n;i++){
		ans=max(ans,tar(i)-i+1);
	}
	
	cout << ans << '\n';
	
	return 0;
}
