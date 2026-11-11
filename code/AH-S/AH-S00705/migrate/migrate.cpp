#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN=2e6+10;
ll n,d,a[MAXN]={},C,t,dp[MAXN][2]={},pd[MAXN]={},pa[MAXN]={1},ans,ans1,gra[MAXN]={};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
	cin>>C>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++){
			dp[i][0]=0;dp[i][1]=0;pa[i]=1;pd[i]=0;
		}
		ans=0;ans1=0;
		for(int i=1,last=1;i<=n;i++){
			while(a[i]-a[last]>d)last++;
//			cout<<"check:"<<last<<" to "<<i;
			if(last==i)continue;
			else {
				pa[i]=last;
				for(int j=pa[last];j<=i;j++)gra[j]=0;
				for(int j=i-1;j>=last;j--){
					int u=pa[j];
					for(int k=u;k<last;k++)gra[k]++;
				}
				for(int j=pa[last];j<last;j++){
					if(gra[j]==1){
						dp[i][1]+=(dp[last][0]+dp[last][1]);
						pd[last]+=dp[i][1];
					}
					else if(gra[j]==2){
						dp[i][0]++;
						pd[gra[j]]++;
					}
				}
			}
//			cout<<",it is "<<dp[i][0]+dp[i][1]<<"\n";
		}
		for(int i=n,last=n;i>=1;i--){
			while(a[last]-a[i]>d)last--;
			if(last==i+1){
				pd[i]+=pd[last];
			}
		}
		for(int i=1;i<=n;i++){
			ans+=(dp[i][0]+dp[i][1]);
			ans1+=pd[i];
//			cout<<dp[i]<<" ";
		}
		cout<<ans1<<"\n";
	}
	return 0;
}
