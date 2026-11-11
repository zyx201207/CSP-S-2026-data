#include<bits/stdc++.h>
using namespace std;
long long dp[2005][2005];
long long a[200005];
bool useful[200005];
int clean_not(int Size){
    int new_size=1;
	for(int i=1;i<=Size;i++){
		if(useful[i]){
			a[new_size]=a[i];
			new_size++;
		}
	}
	return new_size-1;
}
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	for(int i=0;i<2005;i++){
		for(int j=0;j<2005;j++){
			dp[i][j]=0;
		}
	}
	long long n,m;
	cin>>n>>m;
	if(n<=2000){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			dp[i][1]=max(dp[i-1][1],a[i]);
		}
		for(long long i=1;i<=n;i++){
			for(int j=2;j<=min(m,i);j++){
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]&a[i]);
			}
		}
		cout<<dp[n][m];
		return 0;
	}
	else 
    {
		for(int i=1;i<=n;i++)cin>>a[i];
		sort(a+1,a+n+1,cmp);
		long long Pw[36];
		Pw[0]=1;
		for(int i=1;i<=35;i++)Pw[i]=Pw[i-1]*2;
	    long long cut=0;
	    for(int i=1;i<=35;i++)if(a[m]>=Pw[i])cut=i;
	    for(int i=1;i<=n;i++)a[i]=a[i]&(Pw[cut+1]-1);
	    long long count[36];
	    for(int i=0;i<36;i++)count[i]=0;
	    for(int i=1;i<=n;i++){
	    	for(int j=0;j<=30;j++){
	    		if(a[i]&(1<<j))count[j]++;
			}
		}
		long long ans=0;
		for(int i=30;i>=0;i--){
			if(count[i]>=m){
				for(int j=1;j<=n;j++){
					if(a[j]&(1<<i))useful[j]=true;
					else useful[j]=false;
			    }
			    n=clean_not(n);
			    ans=ans|(1<<i);
			    for(int j=0;j<36;j++)count[j]=0;
			    for(int j=1;j<=n;j++){
			    	for(int k=0;k<=30;k++){
			    		if(a[j]&(1<<k))count[k]++;
					}
				}
			}
		}
		cout<<ans;
	}
	return 0;
}
