#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long x[2000005]={0},d,q,sum=0;
int sss(int z){
	int dp[200005]={0},ss[200005]={0};
	dp[z]=0;
	while(z<n){
		q=z+1;
		while(x[q]-x[z]<=d&&q<=n){
			if(dp[z]+1<=dp[q]&&dp[q]!=0){
				dp[q]=dp[z]+1;
				ss[q]++;
			}
			if(dp[q]==0){
				dp[q]=dp[z]+1;
				ss[q]++;
			}
			q++;
		}
		z++;
	}
	int s=0;
	for(int i=1;i<=n;i++){
		if(ss[i]==2){
			s++;
		}
	}
	return s;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int k=1;k<=t;k++){
		sum=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<n;i++){
			sum=sum+sss(i);
		}
		cout<<sum<<endl;
	}
	return 0;
}
