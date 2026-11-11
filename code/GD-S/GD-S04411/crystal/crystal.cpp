#include <bits/stdc++.h>
using namespace std;
long long n,m,ans;
long long sum[500005];
long long a[500005];
long long b[500005];
bool cmp(long long q,long long w){
	return q<w; 
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	//	return 0;
	}
	
	for(int i=2;i<=n;i++){
		long long left=1,right=i-1;
		if(a[i]-a[i-1]>m)continue;
		while(left<right){
			long long mid=(left+right)/2;
			long long x=sum[i-1]-sum[mid-1];
			if((long)a[i]*(i-mid)-x>m){
				left=mid+1;
			}else{
				right=mid;
			}
		//	cout<<left<<' '<<right<<endl;
		}
		
	//	cout<<right<<endl;
		//cout<<endl;
		ans=max(ans,i-right+1);
	}
	cout<<ans;
	
	return 0;
} 
