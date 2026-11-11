#include<bits/stdc++.h>
using namespace std;
int t,n,c,d,x[1000005],dp[100005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int sum=0;
		cin>>n>>d;
		for(int j=1;j<=n;j++) cin>>x[j];
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
			    for(int k=1;;k++){
			    	if(j-k<=0) break;
			    	if(x[j-k]<x[j]-d||x[j]-d<=0) break;
			    	int neww=dp[j-k]+1;
			    	if(neww==dp[j]) sum++;
			    	dp[j]=min(dp[j],neww);
		    	}
		    }
		}
		cout<<sum<<endl;
	}
}


