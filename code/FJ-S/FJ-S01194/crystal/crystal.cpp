#include<bits/stdc++.h>
using namespace std;
long long a[500005],sum[500005];
int main(){
    freopen("crystal.in","r",stdin);
   freopen("crystal.out","w",stdout);
    long long n,m,i,j,cnt=0,ans=0;
    cin>>n>>m;
    for(i=1;i<=n;i++){
    	cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(i=1;i<=n;i++){
		long long l=1,r=n,mid;
		cnt=i;
		while(l<=r){
			mid=(l+r)/2;
			if((mid-i+1)*a[mid]-sum[mid]+sum[i-1]<=m){
//				cout<<mid<<" ";
				cnt=mid;
				l=mid+1;
			}else{
				r=mid-1;
			}
		}
		ans=max(cnt-i+1,ans);
//		cout<<endl;
	}
	cout<<ans;
	return 0;
}
