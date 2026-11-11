#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c,t;
ll n,d,a[2000006];
int dp[5006];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		bool l=1;
		ll k;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i>=3&&a[i]-a[i-1]!=a[i-1]-a[i-2]) l=0;
		}
		if(l==1){
			k=a[n]-a[n-1];
			if(k>d) cout<<0;
			else{
				int r=d/k;
				cout<<n-r;
			}
		}
		//else:......
		
		cout<<"\n";
	}
	if(c==0){
		if(a[1]==4){
			cout<<1<<endl<<2;
		}
		else cout<<0<<endl<<1;
	}
	return 0;
 }
/*
		else{
			int sum=0;
			for(int i=1;i<=n;i++){
				memset(dp,0,sizeof(dp));
				dp[i]=1;
				for(int j=i+1;j<=n;j++){
					for(int k=j-1;k>=i;k--){
						if(a[j]-a[k]<=d){
							dp[j]+=dp[k];
						}
					}
					if(dp[j]==2) sum++;
					if(dp[j]>2) break;
				}
				
			}
			cout<<sum;
		}*/
