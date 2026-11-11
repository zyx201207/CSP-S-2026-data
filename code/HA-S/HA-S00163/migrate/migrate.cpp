#include<bits/stdc++.h>
using namespace std;
int c,t,dp[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==11||c==12){
		dp[0]=0,dp[1]=1;
		while(t--){
			int n,d,cnt=0;
			cin>>n>>d;
			for(int i=2;i<=n;i++)
				for(int j=i-d;j<=(i+d-2)/d*d-d+1;j++)
					if(j>=0)
						dp[i]+=dp[j];
			for(int i=1;i<=n;i++){
				int x; 
				cin>>x;
				if(dp[i]==2)
					cnt++;
			}
			cout<<cnt<<endl;
		}
	}
	return 0;
}
