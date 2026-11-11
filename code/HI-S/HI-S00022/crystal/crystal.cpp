#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,a[N],ans=1,cf[N];
bool check(long long x){
	for(int i=x;i<=n;i++){
		int l=n-x+1;
		if(cf[i]-cf[l]<=m)return true;
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<=5000){
		for(int i=2;i<=n;i++){
			long long sum=0,s=1;
			for(int j=i-1;j>=1;j--){
				sum+=abs(a[i]-a[j]);
				if(sum>m)break;
				s++;
			}
			ans=max(ans,s);
		}
		cout<<ans;
		return 0;
	} 
	for(int i=1;i<=n;i++){
		cf[i]=a[i]-a[i-1];
		cf[i]+=cf[i-1];
	}
	long long l=1,r=n;
	while(l<=r){
		long long mid=l+r>>1;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}
		else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
