#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005];
long long s[500005];
long long ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		s[i]=s[i-1]+(i-1)*abs(a[i]-a[i-1]);
	}
	//s[p]  s[q]: s[q]-s[p-1]-(p-1)*(a[q]-a[p-1])
	for(int i=1;i<=n;i++){
		int L=1,R=i,now=i,mid;
		while(L<=R){
			mid=(L+R)/2;
			if(s[i]-s[mid-1]-(mid-1)*(a[i]-a[mid-1])<=m){
				R=mid-1;
				now=mid;
			}else L=mid+1;
		}
		//cout<<now<<" "<<i<<endl;
		ans=max(ans,1ll*(i-now+1));
	}
	cout<<ans<<endl;
	return 0;
}
