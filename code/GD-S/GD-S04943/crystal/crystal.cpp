#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5; 
long long n,m,a[N],ans=0;
bool c(int x){
	long long sum=0;
	for(int i=1;i<=x;i++){
		sum+=a[x]-a[i];
	}
	return sum<=m;
}
bool dc(int x){
	long long sum=sum2=0;
	for(int i=x;i>=1;i--){
		sum+=a[x]-a[i];
		if(sum>m){
			if(sum2>ans){
				return true;
			}else{
				return false;
			}
		}
		sum2++;
	}
	if(sum2>ans){
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
	sort(a+1,a+n+1);
	long long l=1,r=n,mid=0;
	while(l<=r){
		mid=(l+r)/2;
		if(c(mid)){
			l=mid+1;
			ans=mid;
		}else{
			r=mid-1;
		}
	}
	while(a[ans+1]==ans){
		ans++;
	}
	if(dc(ans+1)){
		ans++;
	}
	cout<<ans;

	return 0; 
} 
