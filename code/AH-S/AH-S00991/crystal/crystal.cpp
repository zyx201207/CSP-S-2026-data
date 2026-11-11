#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005];
int dis[6005][6005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    	cin>>a[i];
	sort(a+1,a+n+1);
	if(n>=7000){
    	int sum=0,cnt=1;
    	if(n&1){
			for(int i=1;i<=n/2;i++){
    			if(a[(n+1)/2]-i>0)
					sum+=i;
    			if(sum<=m)
    				cnt++;
    			else 
    				break;
    			if(a[(n+1)/2]+i<=n)
    				sum+=i;
    			if(sum<=m)
    				cnt++;
    			else 
    				break;
			}
			printf("%lld\n",cnt);
		}
		else{
			for(int i=1;i<=n/2;i++){
    			if(a[(n+1)/2]-i>0)
					sum+=i;
    			if(sum<=m&&a[(n+1)/2]-i>0)
    				cnt++;
    			if(sum>m)
    				break;
    			if(a[(n+1)/2]+i<=n)
    				sum+=i;
    			if(sum<=m&&a[(n+1)/2]+i<=n)
    				cnt++;
    			if(sum>m)
    				break;
			}
			printf("%lld\n",cnt);
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			dis[i][j]=abs(a[j]-a[i]);
		sort(dis[i]+1,dis[i]+n+1);
	}
	int mx=0;
	int cnt=0;
	for(int i=1;i<=n;i++){
		int sum=0;
		for(int j=1;j<=n;j++){
			sum+=dis[i][j];
			if(sum>m){
				if(j-1>mx){
					mx=max(j-1,mx);
					cnt=i;
				}
				break;
			}
		}
		if(sum<=m){
			mx=n;
			cnt=a[i];
		}
	}
	printf("%lld\n",mx);
	return 0;
}

