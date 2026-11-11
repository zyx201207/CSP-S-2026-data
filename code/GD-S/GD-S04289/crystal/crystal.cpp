#include<bits/stdc++.h>
using namespace std;
int n,l,r,mid,qmid=-1,ans=0;
long long m,a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	l=1;
	r=n;
	while(l<r){
		mid=l+(r-l)/2;
		long long sum=0;
		for(int i=1;i<mid;i++){
			sum+=a[mid]-a[i];
		}
		if(sum<m){
			l=mid+1;
			qmid=mid;
		}
		if(sum==m){
			ans=mid;
			for(int j=mid+1;j<=n;j++){
					if(a[j]!=a[mid]){
						ans+=j-mid-1;
						break;
					}	
				}
			break;
		}
		if(sum>m){
			r=mid;
			if(qmid!=-1){
				ans=qmid;
				for(int j=qmid+1;j<=n;j++){
					if(a[j]!=a[qmid]){
						ans+=j-mid-1;
					}	
				}
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
