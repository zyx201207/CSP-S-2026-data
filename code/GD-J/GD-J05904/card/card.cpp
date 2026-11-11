#include<bits/stdc++.h>
using namespace std;
int main(){
	int n=0,m=0,dp[500005],op=0,mn[500005],x=0,found=0,appear[500005];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>dp[i];
	}
	for(int j=1;j<=n;j++){
		mn[0]=dp[j-1];
		x=1;
		if(j<n) op=j;
		if(j==n) op=n-1;
		for(int k=op;k<n;k++){
			found=x;
			mn[x]=dp[k];
			for(int q=0;q<=x;q++){
				if(mn[x]==mn[q]){
					found=q;
					for(int w=q;w<=x;w++){
						mn[w]=0;
					}
				}
			}
			mn[found]=dp[k]; 
			x=found+1;
		}
		for(int ki=1;ki<=m;ki++){
			for(int qq=0;qq<=x;qq++){
				if(mn[qq]==ki) appear[ki]+=1;
			}
		}
		for(int e=0;e<=n;e++){
			mn[e]=0;
		}
	}
	for(int uu=0;uu<m;uu++){
		cout<<appear[uu]<<' ';
	}
	return 0;
}
