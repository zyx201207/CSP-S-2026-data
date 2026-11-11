#include<bits/stdc++.h>
using namespace std;
long long m,n,a[500005],pre1[500005],pre2[500005],t1,t2;
inline long long cost(int l,int r){
	long long co=pre2[r]-pre2[l]-(a[r]-a[l])*(l-1);
	return co;
}
int main(){
	ios::sync_with_stdio(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		pre1[i]=pre1[i-1]+a[i];
		pre2[i]=pre2[i-1]+(i-1)*(a[i]-a[i-1]);
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i,mid;
		while(l<r){
			mid=(l+r)/2;
			if(cost(mid,i)<=m){
				r=mid;
			}else{
				l=mid+1;
			}
		}
		if(ans<i-r+1){
			ans=i-r+1;
		}
	} 
	cout<<ans<<endl;
	return 0;
}
//CCF CSP-S T1crystal
