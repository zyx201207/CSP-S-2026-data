#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long int n,m,ans=0;cin>>n>>m;
	long long int a[n]={};
	for(long long int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	long long int l=a[0],r=a[n-1],mid,s=0;
	while(l<r){
		mid=(l+r)/2,s=0;
		auto it=lower_bound(a,a+n,mid);
		long long int x=it-a,i;
		while(a[x]==*it) x++;
		x--;
		for(i=x;i>=0;i--){
			s+=mid-a[i];
			if(s>=m){
				break;
			}
		}
		if(s<=m){
			l=mid+1;
			ans=x;
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
