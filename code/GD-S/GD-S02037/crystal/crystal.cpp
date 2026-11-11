#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,a[N],m,ans,sum[N],l,r;
bool C=1,A=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(abs(a[i])>200)
			C=0;
	}
	sort(a+1,a+n+1);
	if(n<=13300||(n<=53300&&!C)){
		for(int i=1;i<=n;i++){
			sum[i]=a[i+1]-a[i];
			for(int j=i+1;j<n;j++){
				sum[j]=sum[j-1]+(a[j+1]-a[j])*(j-i+1);
			}
			sum[i-1]=0;
			for(int j=i;j<n&&sum[j]-sum[i-1]<=m;j++){
				ans=max(ans,(j-i+1)*1LL);
			}
		}
//		for(int i=1;i<=n;i++){
//			long long mx=1,mm=m;
//			for(int j=i+1;j<=n;j++){
//				if(mm<=(a[j]-a[j-1])*(j-i))
//					break;
//				mx++;
//				mm-=(a[j]-a[j-1])*(j-i);
//			}
//			ans=max(ans,mx);
//		}
		cout<<ans+1;
		return 0;
	}
	else if(C==1){
		for(int i=-200;i<=200;i++){
			long long mx=0,cnt=0;
			for(int j=1;j<=n;j++){
				if(mx+abs(a[j]-i)>m)
					break;
				mx+=abs(a[j]-i);
				cnt++;
			}
			ans=max(ans,cnt);
		}
		cout<<ans;
		return 0;
	}
	sum[1]=a[2]-a[1];
	for(int i=2;i<n;i++){
		sum[i]=sum[i-1]+(a[i+1]-a[i])*i;
	}
	for(int i=1;i<=n;i++){
		long long l=i,r=n-1,mid,ji=0;
		while(l<r){
			mid=(l+r)/2;
			if(sum[mid]-sum[i-1]<=m){
				ji=l;
				l=mid+1;
			}else{
				if(ji==0)
					break;
				else{
					l=ji+1;
					ji=l;
					r=mid;
				}
			}
		}
		ans=max(ans,l-i+1);
	}
	cout<<ans;
	return 0;
}
