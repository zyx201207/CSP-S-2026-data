#include<bits/stdc++.h>
using namespace std;
int c,n,t;
long long x[2000010];
long long q[2000010];
long long dp[2000010];
long long sh[2000010],d;
int fr=0,tot=0;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
   cin>>c>>t;
   while(t--){
	   cin>>n>>d;
	   for(int i=1;i<=n;i++)cin>>x[i];
	   if(c<=10){
		   long long ans=0;
		   for(int i=1;i<=n-3;i++){
			       tot=fr=0;
			       dp[i]=0;
			       q[++tot]=i;
			       sh[0]++;
			   for(int j=i+1;j<=n;j++){
				   
				   while(fr<tot&&x[j]-x[q[fr+1]] > d){
					   sh[dp[q[fr+1]]]--;
					   fr++;
				   }
				   dp[j]=dp[q[fr+1]]+1;
				   
				   if(sh[dp[q[fr+1]]]==2)ans++;
				   while(fr<tot){
					    if(dp[q[tot]]>dp[i]){
					    sh[dp[q[tot]]]--;
                        tot--;
					    }
					    else break;
				   }
				   q[++tot]=j;
				   sh[dp[q[tot]]]++;
			   }
			   
			   while(fr<tot){
				   sh[dp[q[fr+1]]]--;
				   fr++;
			   }
		   }
		   cout<<ans<<'\n';
	   }
   }
    return 0;
}
