#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+7;
int nums[N];
int n,m;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>nums[i];
	sort(nums+1,nums+1+n);
	int sum=0,ans=-1,l=1;
	for(int i=1;i<=n;i++){
		if(nums[i]*(i-l)-sum<=m){
			ans=max(ans,i-l+1);
		}else{
			sum-=nums[l];
			l++;
		}
		sum+=nums[i];
	}
	cout<<ans;
    return 0;	
}
