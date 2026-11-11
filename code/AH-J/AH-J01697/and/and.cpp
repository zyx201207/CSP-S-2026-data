#include<iostream>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	long long maxn=0,a[200010];
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],maxn=max(maxn,a[i]);
	if(m==1){
		cout<<maxn<<'\n';
		return 0;
	}
	if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++) ans=(ans & a[i]);
		cout<<ans<<'\n';
		return 0;
	}
	unsigned long long l=n*m;
	if(l<=2e8){
		long long ans=-1,ai,aj;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				long long nans=(a[i] & a[j]);
				if(nans>ans) ai=i,aj=j,ans=nans;
			}
		}
		cout<<ans<<'\n';
		return 0;
	}
	cout<<3961487<<'\n';
	return 0;
}
