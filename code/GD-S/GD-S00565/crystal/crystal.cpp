#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const int N=5e5+5;
int n;ull m;ll e[N];
ull pre[N];
int ans=0;
bool check(ll x){
	ull ans=1e18;
	for (int i=x;i<=n;i++){
		int j=i-x+1;
		ull c=e[i]-e[j];
		ull sum=pre[i]-pre[j]-(j-1)*c;
		ans=min(ans,sum);
	}
	return ans<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>e[i];
	sort(e+1,e+n+1);
	for (int i=1;i<=n;i++){
		ull c=e[i]-e[i-1];
		pre[i]=(i-1)*c+pre[i-1];
	}
	int l=1,r=n;
	while (l<=r){
		int mid=l+r>>1;
		if (check(mid)){
			ans=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
} 
