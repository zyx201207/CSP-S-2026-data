#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=0x3fffffff;;
long long a[500005],cha[500005],c[500005],sum_cha[500005];
long long erf(int l,int r,int num){
	if(l>=r){
//		cout<<r<<endl;
		return r;
	}
	long long mid=(l+r)/2;
	long long sum=sum_cha[mid]-sum_cha[num]-(num-mid)*cha[num];
//	cout<<l<<' '<<mid<<' '<<r<<' '<<sum<<endl;
	if(sum>m){
//		ans=min(ans,mid);
		erf(mid+1,r,num);
	}
	else{
		erf(l,mid,num);
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=n-1;i>=1;i--){
		c[i]=a[i+1]-a[i];
		cha[i]=cha[i+1]+c[i];
		sum_cha[i]=sum_cha[i+1]+cha[i];
	}
//	for(int i=1;i<=n;i++){
//		cout<<c[i]<<" ";
//	}
//	cout<<endl;
//	for(int i=1;i<=n;i++){
//		cout<<cha[i]<<' ';
//	}
//	cout<<endl;
//	for(int i=1;i<=n;i++){
//		cout<<sum_cha[i]<<' ';
//	}
//	cout<<endl;
	long long maxx=-1;
	ans=-1;
	for(int i=1;i<=n-1;i++){
//		cout<<i<<endl;
		ans=max(i-erf(1,i,i)+1,ans);
	}
	
//	for(int i=1;i<=4;i++){
//		
//		long long sum=sum_cha[i]-sum_cha[4]-(4-i)*cha[4];
//		cout<<sum<<' '<<sum_cha[i]<<" "<<sum_cha[4]<<' '<<(4-i)*cha[4]<<endl;
//	}
	for(int i=1;i<=n;i++){
		long long io=sum_cha[i];
		if(io<=m){
			if(ans<(n-i+1)){
				ans=n-i+1;
			}
			break;
		}
	}
	cout<<ans;
	return 0;
}
