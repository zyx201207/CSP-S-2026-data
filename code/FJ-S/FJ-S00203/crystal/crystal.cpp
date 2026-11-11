#include <bits/stdc++.h>
using namespace std;
long long a[500005];	
int n,ans=0;
long long m;
void check(long long p){
	int m1=m;
	int ans1=0;
//	long long l=1,r=n;
//	while(l<r){
//		long long mid=(l+r)/2;
//		if(mid>p){
//			r=mid-1;
//		}
//		else{
//			l=mid+1;
//		}
//	}
//	cout<<r<<"       999"<<endl;
	for(int i=n;i>=1;i--){
		if(p>=a[i] && m1>=(p-a[i])){ 
			m1-=(p-a[i]);
			ans1++;
		}
		if(p>=a[i] && m1<(p-a[i])){
			break;
		}
	}
	ans=max(ans,ans1);
	return;
}
//int dp[20][1005][1005];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	sort(a+1,a+n+1);
	if(n<=5000){
		for(long long i=a[1];i<=m+a[n];i++){
			check(i);
		} 
		cout<<ans;	
	}
	else{
		int ans=0;
		long long b1;
		bool flag=false;
		for(int i=1;i<=n;i++){
			b1=(a[2]+(a[2]-a[1])*(i-1))*i/2;
			if(b1>m){
				break;
			}
			ans++;
		}
//		if(flag)
		cout<<ans;
	}
	
//	long long l=a[1],r=a[n];
//	while(l<r){
//		long long mid=(l+r)/2;
//		if(!(check(mid))){
//			r=mid-1;
//		}
//		else{
//			l=mid+1;
//		}
//	}
//	cout<<l<<endl;
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			for(int x=0;x<=j;x++){
//				dp[i][j][x]=max()
//			}
//		}
//		
//	}
} 
