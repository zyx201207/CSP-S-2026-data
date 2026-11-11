#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e6+10;
int a[maxn];
int c[maxn];
int pre[maxn];
int n,m;
bool check(int x){
	for(int i=x;i<=n;i++){
		int cnt=0;
		for(int j=i-x+2;j<=i;j++){
			cnt+=pre[i]-pre[j-1];
		}
		if(cnt<=m)return true;
	}
	return false;
}
signed main(){
	freopen("crystal4.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		//c[i]=a[i]-a[i-1];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		c[i]=a[i]-a[i-1];
		pre[i]=pre[i-1]+c[i];
	}
	int l=1,r=n;
	int ans=0;
	while(l<=r){//³¤ 
		int mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
} 
