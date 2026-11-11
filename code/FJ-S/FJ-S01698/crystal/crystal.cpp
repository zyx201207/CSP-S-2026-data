#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,ans;
int a[N],qq[N];

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i){
		qq[i]=qq[i-1]+a[i];
		if(n<=5000){
			int sum=0;
			int now=i;
			for(int j=i-1;j>=1;--j){
				if(sum+a[i]-a[j]>m) break;
				sum+=a[i]-a[j];
				now=j;
			}
			ans=max(ans,i-now+1);
		}
		else{
	//		cout<<i<<"\n";
			int l=1,r=i-1;
			int tt=0;
			while(l<=r){
				int mid=(l+r)>>1;
				tt=a[i]*(i-mid)-qq[i-1]+qq[mid-1];
	//			cout<<i-mid<<"\n";
	//			cout<<qq[i-1]<<" "<<qq[mid-1]<<"\n";
				if(tt>m) l=mid+1;
				else r=mid-1;
	//			cout<<mid<<" "<<tt<<" "<<l<<" "<<r<<"\n";
			}
	//		cout<<i<<" "<<l<<" "<<now<<"\n";
	//		cout<<tt<<" "<<sum<<"\n";
			ans=max(i-l+1,ans);	
		}
	}
	cout<<ans;
	return 0;
}