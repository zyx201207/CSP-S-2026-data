#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005],n,m;
int check(int x){
	int ans=1,cnt=m,i=x-1;
	while(i>=1 && cnt>=a[x]-a[i]){
		cnt=cnt-a[x]+a[i];
		ans++;
		i--;
	}
	return ans;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	int ans=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans=max(ans,check(i));
	}
	cout<<ans;
} 
