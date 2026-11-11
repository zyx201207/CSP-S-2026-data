#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 500005
int n,m,a[N];
bool ch(int x){
	int sum = 0;
	bool f=false;
	for(int i = 1;i <= n;i++){
		if(i <= x){
			sum+=(a[i]-a[i-1])*(i-1);
		}else{
			sum+=(a[i]-a[i-1])*(x-1)-(a[i-1]-a[i-x]);
		}
		if(i>=x&&sum<=m){
			f=true;
			break;
		}
	}
	return f;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	int l = 1,r = n,ans=1;
	while(l <= r){
		int mid=(l+r)>>1;
		if(ch(mid)){
			l=mid+1;
			ans=mid;
		}else{
			r=mid-1; 
		}
	}
	cout << ans << endl;
	return 0;
} 
