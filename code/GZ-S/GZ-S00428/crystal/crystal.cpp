//GZ-S00428 陈则睿 贵阳实验三中 
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010];
long long sub[500010],sub2[500010],sum[500010],sum2[500010];
long long maxx=-1e16,minn=1e16;
int check(int i,int j){
	return sum2[i]-sum2[j]-(j)*(sum[i]-sum[j])<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){cin>>a[i];maxx=max(a[i],maxx),minn=min(minn,a[i]);}
	sort(a,a+n);
	sub[0]=a[1]-a[0];    sub2[0]=sub[0];
	for(int i=1;i<n-1;i++){
		sub[i]=a[i+1]-a[i];    
		sub2[i]=(i+1)*sub[i];
	} 
	sum[0]=sub[0];sum2[0]=sub2[0];
	for(int i=1;i<n-1;i++){
		sum[i]=sum[i-1]+sub[i];
		sum2[i]=sum2[i-1]+sub2[i];
	}
	int ans=0;
	for(int i=0;i<n-1;i++){
		int l=0,r=i,mid=(l+r)/2;
		while(l<r){
			mid=(r+l)/2;
			if(check(i,mid)){
				r=mid;
			}else{
				l=mid+1;
			}
		}
//		cout<<l<<' '<<r<<' '<<'\n';
//		for(int j=0;j<=i;j++){
//			cout<<sum2[i]-sum2[j]-(j)*(sum[i]-sum[j])<<' ';
//		}
//		cout<<'\n';
		ans=max(ans,i-l+2);
	}
	cout<<ans;
} 
