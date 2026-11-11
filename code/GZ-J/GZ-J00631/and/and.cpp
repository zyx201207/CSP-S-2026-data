//GZ-J00631 六盘水市第二十四中学 廖国吉
#include<bits/stdc++.h>
using namespace std;
int c,n,m,a[100005],s,dp[1005][1005][105],h[100005],b[100005];
int main(){
	freopen("and.in","w",stdin);
    freopen("and.out","r",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			 c=max(c,a[i]);
		} 
		cout<<c;
		return 0;
	}
	if(m==n){
		for(int i=1;i<=n;i++){
	       b[i]=a[i]&b[i-1];
		}
		cout<<b[n];
		return 0;
	}
	sort(a+1,a+n+1);
	s=n;
	for(int k=1;k<=n;k++){
	    for(int i=1;i<n;i++){
		    for(int j=i;j<n;j++){
			    if(k==1){
			    dp[k][i][j]=a[i]&a[j];
			    for(int t=1;t<=n;t++) h[k]=max(dp[k][i][j],h[k]);
			    }
			    else {
			    dp[k][i][j]=dp[k-1][i][j]&a[j+2];
			    for(int t=1;t<=n;t++){
			  	h[k]=max(dp[k][i][j],h[k]);
				}
				}
		    }
	    }
	    n--;
	}
	cout<<h[m-1];
	return 0;
}
