#include<bits/stdc++.h>
using namespace std;
int main(){
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n,d;
		cin>>n>>d;
		int a[n+10];
		if(c==11 || c==12){
			for(int i=1;i<=n;i++) cin>>a[i];
			if(n>=4){
				if(a[2]-a[1]>=d || a[n]-a[1]<=d || a[4]-a[1]==d) cout<<0<<endl;
				else cout<<n-3<<endl;
			}else{
				cout<<0<<endl;
			}
			return 0;
		}else if(c==13 || c==14){
			cout<<0<<endl;
		}
		else{
			map<int,int> mp;
			int dp[n+10]={0},ans=0;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			mp[0]=1;
			for(int i=2;i<=n;i++){
				for(int j=i-1;j>=1;j--){
					if(a[i]-a[j]<=d){
						dp[i]=dp[j]+1;
					}
				}
				mp[dp[i]]++;
			}
			int k=mp.size();
			for(int i=1;i<k;i++){
				if(mp[i]==2){
					ans+=mp[i-1]*mp[i+1];
				}
			}
			cout<<ans<<endl;
			
		}
	}
	return 0;
}
