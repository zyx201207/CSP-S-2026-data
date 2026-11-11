#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,ans;
ll a[500005],b[500005],sum;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)/2;
		bool flag=false;
		for(int i=1;i<=n-mid+1;i++){
			int j=i+mid-1;
			sum=0;
			for(int k=i;k<j;k++){
				sum+=a[j]-a[k];
			}
			if(sum<=m){
				flag=true;
				break;
			}
		}
		if(flag){
		    l=mid+1;
			ans=mid; 
		}
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}
