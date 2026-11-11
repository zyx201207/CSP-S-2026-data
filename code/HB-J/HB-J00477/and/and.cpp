#include<bits/stdc++.h>
using namespace std;
long long dp[200001];
long long a[200001];
int v[200001];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
		cin>>a[i];
		dp[i]=a[i];
	}
	int u=0;
	for(int i=0;i<m-1;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				if(!v[k]){
					u=k;
					break;
				} 
			}
			for(int k=0;k<n;k++){
				if(!v[k]){
					if(dp[j]<(dp[j]&a[k])){
						u=k;
						dp[j]=(dp[j]&a[k]);
					}
				}
			}
			v[u]=1;
		}
	}
	cout<<dp[n-1];
	return 0;
}
/*5 3
31 3 1 15 7*/
