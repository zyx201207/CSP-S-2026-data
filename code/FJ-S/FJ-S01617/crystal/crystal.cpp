#include<bits/stdc++.h>
#define N 500050
using namespace std;
long long n,m,a[N],sum,ans;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=2,left=1;i<=n;i++){
		sum+=(i-left)*(a[i]-a[i-1]);
		while(sum>m){
			sum-=a[i]-a[left];
			left++;
		}
		ans=max(ans,i-left+1LL);
	}
	cout<<ans;
	return 0;
} 
