#include<bits/stdc++.h>
using namespace std;
int x[10005];
int dp[10005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int sum=0;
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]==d+1){
					sum++;
				}
			}
		}
		cout<<sum<<endl;
		sum=0;
	}
	return 0;
}
