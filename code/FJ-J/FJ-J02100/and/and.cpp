#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200100],b[35][200010],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		long long c=a[i],x=1;
		while(c>0){
			if(c%2==1){
				b[x][i]=1;
				b[x][200001]+=1;
			}
			c=c/2;
			x+=1;
		}
	}
	if(m==n){
		ans=a[1];
	   for(int i=2;i<=n;i++){
	   	ans=ans&a[i];
	   }	
	   cout<<ans;
	   return 0;
	}
	else if(m==1){
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
			cout<<ans;
			return 0;
		}
	}
//	else if(m==2){
//		for(int i=1;i<n;i++){
//			for(int j=i+1;j<=n;j++){
//				ans=max(ans,a[i]&a[j]);
//			}
//		}
//		cout<<ans;
//		return 0;
//	}
	for(int i=31;i>=1;i--){
		if(b[i][200001]>=m){
		    for(int j=1;j<=n;j++){
		    	if(b[i][j]==0){
		    		for(int l=1;l<=i-1;l++){
		    			if(b[l][j]==1){
		    				b[l][200001]-=1;
		    				b[l][j]=0;
						}
					}
				}
			}
		}
	}
	for(int i=31;i>=1;i--){
		long long sum=1;
		if(b[i][200001]>=m){
		    for(int j=1;j<=i-1;j++){
		    	sum=sum*2;
			}
			ans+=sum;
		}
	}
	cout<<ans;
	return 0;
}
/*
5 3
31 3 1 15 7
*/