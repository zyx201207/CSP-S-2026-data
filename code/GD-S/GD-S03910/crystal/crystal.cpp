#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005];
int s[500005];
bool check(int x,int i){
	int sum=abs((i-x+1)*a[i]-(s[i]-s[x-1]));
	return sum<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i-1,qwe=i;
		while(l<=r){
			int mid=l+r>>1;
			if(check(mid,i)){
				r=mid-1;
				qwe=mid;
			}
			else{
				l=mid+1;
			}
		}
		ans=max(ans,i-qwe+1);
	}
	cout<<ans<<"\n";
	return 0;
}
