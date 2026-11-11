#include <bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	long long m,sum=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1,r=2,ans=0,cnt=1,f=1;
	while(r<=n){
		if(f){
			sum+=(r-l)*(a[r]-a[r-1]);
		}
		if(sum<=m){
			cnt++;
			ans=max(ans,cnt);
			r++;
			f=1;
		}else{
			sum-=a[r]-a[l];
			f=0;
			cnt--;
			l++;
		}
		if(l==r){
			r=l+1;
			cnt=1;
			sum=0;
		}
	}
	cout<<ans;
	return 0;
} 
