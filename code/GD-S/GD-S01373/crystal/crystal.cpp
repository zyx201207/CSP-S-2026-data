#include<bits/stdc++.h>
using namespace std;
long long n,a[500009],m,sum[500009],ans;
long long fd(long long z,long long ii){
	long long l,mid,r,res;
	l=0;r=ii-1;
	res=0;
	while(l<=r){
		mid=(l+r)/2;
		if(z>=sum[mid]-(a[ii]*mid)){
			
			r=mid-1;
		}
		else{
			res=l;
			l=mid+1;
		}
	}
	return l;
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
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		long long xx;
		xx=fd(m+sum[i]-i*a[i],i);
		//cout<<xx<<" "<<i<<endl;
		ans=max(i-xx,ans);
	}
	cout<<ans;
} 
