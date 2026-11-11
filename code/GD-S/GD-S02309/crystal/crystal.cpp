#include<iostream>
#include<algorithm>
using namespace std;
long long n,m,a[500010],sum[500010],f[500010],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<i;j++){
			long long sumlr=sum[i-1]-sum[j];
			if((i-j)*a[i]-sumlr<=m){
				f[i]=i-j+1;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++){
		ans=max(ans,f[i]);
	}
	cout<<ans<<"\n";
	return 0;
}

