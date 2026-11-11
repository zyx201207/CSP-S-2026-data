#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		int ans=0;
		for(int i=1;i<=n;i++){
			int l=i+1,r=n+1;
			while(l<r){
			int mid=(l+r)/2;
				if(a[mid]-a[l]>=d&&mid-l>=2)l=mid+1;
				else r=mid;
			}
			ans+=(n-l+1);
		}
		cout<<ans<<endl;
	}
	return 0;
}
