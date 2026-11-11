#include<bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
const int N=5e5+5;
int n,a[N],m,ans=0;
bool check(int x){
	int t=0;
	for(int i=1;i<=x;i++){
		t+=a[x]-a[i]; 
	}
	if(t<=m) return true;
	else return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int l=0,r=n+1,mid,cnt=0;
	while(l<=r){
		mid=l+r>>1;
		if(check(mid)){
			cnt=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	cout<<cnt;
	return 0;
}
