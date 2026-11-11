#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N],sum[N];
long long ans[N];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
	int n,m,f=1;
	cin>>n>>m;
    for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]!=a[i-1]&&i>=2){
				f=0;
			}
			sum[i]=sum[i-1]+a[i];
			ans[i]=1e12;
		}
		sort(a+1,a+n+1);
		ans[1]=0;
		for(int i=1;i<=n;i++){
			for(int cnt=1;cnt<=n-i;cnt++){
				int j=cnt+1;
				ans[j]=min(ans[j],a[i+cnt]*j-(sum[i+cnt]-sum[i-1]));
				//if(ans[j]==-2)cout<<cnt<<" "<<a[i]<<" "<<i<<" "<<sum[i+cnt]<<" "<<a[i-1]<<endl;
			}
		}
	//	for(int i=1;i<=n;i++){
	//		cout<<ans[i]<<" ";
	//	}
		//cout<<endl;
		int l=1,r=n;
		while(l<r){
			int mid=(l+r)/2;
			if(ans[mid]>m) r=mid;
			else l=mid+1;
		}
		if(f==0){
			cout<<r-1;
		}else{
			cout<<n;
		}
    
	return 0;
}
