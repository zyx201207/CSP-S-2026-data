#include<bits/stdc++.h>
using namespace std;

long long a[200005];
long long dp[200005];
long long sum;



int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n,m;cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	sum=0;
	dp[1]=a[1];
	//for(int i=1;i<=n-m;i++){
		int mv=0;
		for(int j=1;j<=n;j++){
			if(mv<=m){
				if((a[j]&dp[j-1])>a[j]){
					dp[j]=a[j]&dp[j-1];
					mv++;
				}
				else {
					dp[j]=a[j];
				}
			}
		}
	//}
	cout<<dp[n]<<'\n';
	return 0;
}
