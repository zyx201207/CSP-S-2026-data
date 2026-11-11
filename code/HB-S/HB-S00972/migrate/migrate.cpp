#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,a[500100],s[200],n,d,dp[1010][1010]={0},l=1;
	cin>>c>>t;
	while(t>0){
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<n;i++){
			for(int j=i+2;j<=n;j++){
				for(int k=i+1;k<j;k++){
					if(a[k]-a[i]<=d && a[j]-a[k]<=d)
					dp[i][j]++;
				}
				if(a[j]-a[i]<=d){
					continue;}
				if(dp[i][j]==2) s[l]++;
			}
		}
		l++;
		t--;
	}
	for(int i=1;i<=l-1;i++)
	cout<<s[i]<<endl;
}
