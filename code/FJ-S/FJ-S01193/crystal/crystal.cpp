#include <bits/stdc++.h>
using namespace std;
long long a[500005];
__int128 qz[500005],cha[500005];
int n,m;
bool ck(int l,int r){
	__int128 sum=cha[l]-cha[r]-(r-1)*(a[l]-a[r]);
	if(sum<=m){
		return true;
	}else{
		return false;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		qz[i]=qz[i-1]+a[i];
		cha[i]=(i-1)*a[i]-qz[i-1];
	}
	long long ans=1;
	for(long long i=1;i<=n;i++){
		long long l=1,r=i,mid=(l+r)/2,num=i;
		while(l<=r){
			if(ck(i,mid)){
				num=mid;
				r=mid-1;
			}else{
				l=mid+1;
			}
			mid=(l+r)/2;
		}
		ans=max(ans,(i-num+1));
	}
	cout<<ans;
	
	return 0;
}