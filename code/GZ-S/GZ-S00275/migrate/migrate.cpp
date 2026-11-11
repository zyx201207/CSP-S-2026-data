//GZ-S00275,刘睿羽,华东师范大学附属贵阳学校 
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int s,cnt;
int n,m,c,t;
int dis[N];
int a[N];
int dp[N];
signed main(){
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    cin>>c>>t;
    while(t--){
    	for (int i=1;i<=N;i++) dis[i]=dp[i]=a[i]=0;
    	cin>>n>>m;
    	for (int i=1;i<=n;i++){
    		cin>>a[i];
    		if (a[1]+m>=a[i]) s=i;
		}
		for (int i=1;i<=n;i++){
		    int l=1,r=i;
		    while(l<=r){
		    	int mid=(l+r)/2;
		    	if (a[mid]+m>=a[i]) r=mid-1;
		    	else l=mid+1;
			}
			dis[i]=l;
		
		}
		for (int i=1;i<=s;i++) dp[i]=1;
		for (int i=s+1;i<=n;i++){
			for (int j=dis[i];j<i;j++){
				dp[i]+=dp[j];
			}
			if (dp[i]==0) dp[i]=1;
			if (dp[i]==2) cnt++;
		}
		cout<<cnt<<"\n";
		
	}
   	
	return 0;
}   
