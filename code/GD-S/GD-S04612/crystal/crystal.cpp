#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500055],pre[500055],ans=-1;
long long divsearch(long long val,long long index){
	int l=0,r=n,mid=(l+r)>>1;
	while(l<r){
		if(val-mid*a[index]<=pre[index]-pre[mid-1]){
			r=mid;
		}else{
			l=mid+1;
		}
		mid=(l+r)>>1;
	}
	return l;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){	
			ans=max(ans,i-divsearch(i*a[i]-m,i));
	}
	cout<<ans;
	return 0;
} 
