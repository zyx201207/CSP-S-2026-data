#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m;
int a[N],sum[N];
int ans=1;
map<int,int>mp;
bool check(int x,int y){
	int num=0;
	int ssum=0;
	int len=y-x;
	ssum=a[y]*len-(sum[y-1]-sum[x-1]);
	return ssum<=m; 
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mp[a[i]]++;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=n;i>=1;i--){
		int l=1,r=i;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(mid,i))r=mid-1;
			else l=mid+1;
		}
//		cout<<i-r<<'\n';
		ans=max(ans,i-r);
		if(r==0)break;
//		cout<<ans<<'\n';
	}
	cout<<ans;
	return 0;
} 
