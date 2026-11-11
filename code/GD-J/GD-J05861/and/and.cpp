#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2e5+5;
int n,m;
long long a[N],dp[N],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("ans.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
      
	}
	sort(a+1,a+1+n);
//	cout<<"&&& ";
//	for(int i=1;i<=n;i++){
//		for(int j=m;j>=0;j--){
//			dp[j]=max(dp[j],dp[j-1]&a[i]);
//		}
//	}
    ans=a[n];
 //   cout<<ans<<" ";
//    cout<<"$$ ";
    for(int i=n-1;i>=n-m+1;i--){
//    	cout<<"*"<<i<<' ';
    //	cout<<a[i]<<" ";
    	ans&=a[i];
	}
	
	cout<<ans;
	return 0;
} 
