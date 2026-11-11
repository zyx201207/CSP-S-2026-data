#include<bits/stdc++.h>
using namespace std;
long long a[500005],m,sum[500005];
int n,ans=1; 
bool ab(long long x,long long y){
	return x<y;
}
bool check(int x,int mid){
	return (x-mid)*a[x]-(sum[x-1]-sum[mid-1])<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n,ab);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=2;i<=n;i++){
		int l=1,r=i-1,an=i;
		while(l<=r){
			int mid=(l+r)/2;
			if(check(i,mid)){
				an=mid;
			    r=mid-1;	
			}else l=mid+1;
		}
		ans=max(ans,i-an+1);
	}
	cout<<ans;
	return 0;
}
