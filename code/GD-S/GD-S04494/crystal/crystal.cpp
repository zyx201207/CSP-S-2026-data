#include<bits/stdc++.h>
using namespace std;
long long a[500007],b[500007];
long long n,m;
long long ans=0;
bool cheak(long long x,long long y){
	long long sum=(x-y)*a[x]-b[x-1]+b[y-1];
//	cout<<x<<" "<<y<<" "<<sum<<endl; 
	if(sum<=m){
		ans=max(ans,x-y+1);
		return true;
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=a[i]+b[i-1];
	}
//	for(int i=1;i<=n;i++){
//		cout<<b[i]<<" ";
//	}
//	cout<<endl;
	for(int i=n;i>=1;i--){
		long long l=0;
		long long r=i+1;
		if(!cheak(i,i-1)){
			continue;
		}
		while(r-l>1){
			long long mid=(l+r)/2;
			if(cheak(i,mid)){
				r=mid;
			}
			else{
				l=mid;
			}
		}
		if(r==i){
			r--;
		}
		ans=max(ans,i-r+1);
	}
	cout<<ans;
	return 0;
}
