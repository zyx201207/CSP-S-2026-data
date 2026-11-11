#include<bits/stdc++.h>
using namespace std;
int a[5005];
int l[5005][5005];
int dp[5005][5005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--){
		int n,d,minn=0,cnt=0,f=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				l[i][j]=abs(a[j]-a[i]);
				dp[i][j]=l[i][j];
			}
		}
		for(int i=1;i<=n;i++){
			int k=i+1;
			for(int j=1+i;j<=n;j++){
				if(l[i][j]<=d){
					dp[i][j]=min(dp[i][k]+l[i][j],dp[i][j]);
					minn=min(dp[i][j],minn);
					k=j;
				}
			}
			for(int j=1;j<=n;j++){
				if(minn==dp[i][j]&&f==0) f=1;
				else if(minn==dp[i][j]&&f>=1) f=2;
			}
			if(f==1) cnt++;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
