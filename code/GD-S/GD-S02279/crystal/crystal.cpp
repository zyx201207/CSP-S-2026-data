#include<bits/stdc++.h>
using namespace std;

long long n,m,ans,a[500005];

bool check(int x){
	for(int i=x;i<=n;i++){
		int sum=0;
		for(int j=0;j<x;j++){
			sum+=a[i]-a[i-j];
		}
		if(sum<=m){
			return true;
		}
	}
	return false;
}

int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	
	sort(a+1,a+1+n);
	
	if(n<500005){
		for(int i=1;i<=n;i++){
			long long cnt=1,sum=m;
			for(int j=i+1;j<=n;j++){
				if(sum-a[i]+a[j]<0){
					break;
				}
				sum-=a[i]-a[j];
				cnt++;
			}
			ans=max(cnt,ans);
		}
	}
	else{
		int l=1,r=n;
		while(l<r){
			int mid=(l+r)/2;
			if(check(mid)){
				ans=mid;
				l=mid+1;
			}
			else{
				r=mid-1;
			}
		}
	}
	
	cout<<ans<<endl;
	
	return 0;
}
