//GZ-S00160 贵阳市第十七中学 汪夏乐 
#include<bits/stdc++.h>
using namespace std;
long long a[200010];
long long n,m;
bool check(int k){
	int c=0;
	for(int i=0;i<n;i++){
		if(i<k){
			c+=a[k-1]-a[i];
			if(i==k-1){
				if(c<=m){
					return 1;
				}
			}
		}else{
			c-=a[i-1]-a[i-k];
			c+=(k-1)*(a[i]-a[i-1]);
			if(c<=m){
				return 1;
			}
		}
		
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
	} 
	sort(a,a+n); 
	int ans=-1;
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
} 
