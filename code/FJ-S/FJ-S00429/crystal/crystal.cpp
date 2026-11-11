#include<bits/stdc++.h>
#define int long long
using namespace std;
// crystal
const int maxn=5e5+7;

int a[maxn],pre[maxn],n,m;

bool check(int i,int mid){
	return mid*a[i+mid-1]-pre[i+mid-1]+pre[i-1] <= m;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.txt","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=1,r=n-i+1,mid,res=0;
		while(l<=r){
			mid=l+(r-l)/2;
			if(check(i,mid)){
				l=mid+1;
				res=mid;
			}
			else r=mid-1;
		}
		ans=max(ans,res);
	}
	cout<<ans;
	return 0;
} 
