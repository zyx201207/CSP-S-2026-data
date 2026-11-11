#include<iostream>
#include<algorithm>
using namespace std;

long long n,m,a[500005],ans=0,link[500005],cnt[500005]={},sum[500005]={},sumc[500005]={};

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(&a[1],&a[n+1]);
	long long now=0;
	a[0]=-2e18;
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i-1]){
			now++;
			link[now]=a[i];
		}
		cnt[now]++;
	}
	if(now==1){
		cout<<n;
		return 0;
	}
	for(int i=1;i<=now;i++){
		sum[i]=sum[i-1]+cnt[i]*link[i];
		sumc[i]=sumc[i-1]+cnt[i];
	}
	//for(int i=1;i<=now;i++) cout<<cnt[i]<<" "<<link[i]<<" "<<sumc[i]<<" "<<sum[i]<<"\n";
	for(int i=1;i<=now;i++){
		long long l=1,r=i-1,as=-1,mid;
		while(l<=r){
			mid=(l+r)>>1;
			if(link[i]*(sumc[i-1]-sumc[mid-1])-(sum[i-1]-sum[mid-1])<=m){
				as=mid;
				r=mid-1;
			}
			else l=mid+1;
		}
		//cout<<as<<"\n";
		if(as==-1) ans=max(ans,cnt[i]);
		else if(as==1) ans=max(ans,sumc[i]);
		else{
			long long lest=m-(link[i]*(sumc[i-1]-sumc[as-1])-(sum[i-1]-sum[as-1]));
			ans=max(ans,sumc[i]-sumc[as-1]+lest/(link[i]-link[as-1]));
		}
	}
	cout<<ans;
	return 0;
}
