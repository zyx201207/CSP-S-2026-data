#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long mx=-100000,mn=100000;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
		mn=min(mn,a[i]);
	}
  	sort(a+1,a+n+1);
	long long sum,cnt=0;
	for(int i=mn;i<=mx;i++){
		sum=0;
		cnt=0;
		for(int j=1;j<=n;j++){
			if(a[j]<i){
				sum+=i-a[j];
				cnt++;	
			}
			else break;
		}
		if(sum<=m && cnt>ans){
			ans=cnt;
			cout<<i<<endl;
		}
	}
//	long long sum=0;
//	for(long long j=2;j<n;j++){
//		for(long long i=j;i<=n;i++){
//			if(sum+b[i]*i<=m){
//				sum+=b[i]*i;
//				ans=max(ans,i);
//			}
//		}
//	} 
	
	
	
	
	
	cout<<ans;
	return 0;
}
