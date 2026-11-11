#include<bits/stdc++.h>
using namespace std;
#define ll long long
int b[300005],d[300005],dp[300005],a[300005],d1[3000005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
    for(int i=n;i>=1;i--){
    	int xa=a[i];
    	if(b[xa]==0){
    	    b[xa]=i; 
		}else{
			d1[i]=0;
		}
	} 
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1]+dl[i];
		dl[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		cout<<dp[i]<<" ";
	}
	return 0; 
} 
