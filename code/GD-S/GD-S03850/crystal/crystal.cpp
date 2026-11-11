#include<iostream>
#include<algorithm> 
#define int long long 
using namespace std;
int n,a[500005],s[500005],m,ans;
bool check(int x,int y){
	return a[y]*(y-x+1)-(s[y]-s[x-1])<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i =1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i =1;i<=n;i++){
		s[i] = s[i-1]+a[i];
	}
	for(int i =1;i<=n;i++){
		int l = 1,r = i;
		while(l<=r){
			int mid = l+(r-l)/2;
			if(check(mid,i))r = mid-1;
			else l = mid+1;
		}
		r++;
		ans = max(ans,i-r+1);
	}
	cout<<ans;
}
