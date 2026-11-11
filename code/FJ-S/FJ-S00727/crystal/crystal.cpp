#include<bits/stdc++.h>
using namespace std;

const int N=5e5+5;
long long n,m,a[N];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long l=n+1,r=n,ans=0,cnt=0,sum=0;
	for(int i=n;i>=2;i--){
		while(sum<=m && l>1){
			l--;
			sum+=a[r]-a[l];
			cnt++;
		}
		//cout<<"l:"<<l<<" "<<"r:"<<r<<" "<<"sum:"<<sum<<" "<<"cnt:"<<cnt<<" >> ";
		if(l==1 && sum<=m){
			ans=max(ans,cnt);
		}
		r--;
		sum-=(cnt-1)*(a[i]-a[i-1]);
		cnt--;
		ans=max(ans,cnt);
		//cout<<"l:"<<l<<" "<<"r:"<<r<<" "<<"sum:"<<sum<<" "<<"cnt:"<<cnt<<" "<<"ans:"<<ans<<endl;
	}
	cout<<ans;
	return 0;
}
