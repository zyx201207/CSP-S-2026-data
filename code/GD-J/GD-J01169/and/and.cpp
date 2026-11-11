#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int dp[2005][2005];
int l[200005];
int qq[200005];
int hh[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    int bj=1;//B
    int bj2=1;//A
    for (int i=1;i<=n;i++){
    	cin>>a[i];
    	dp[i][1]=a[i];
    	if(a[i]!=i-1){
    		bj=0;//B
		}
		long long xl=1;
		long long jsg=0;
		while(xl<=a[i]){
			xl*=2;
			jsg++;
		}
		//cout<<jsg<<"\n";
		if(xl!=a[i]+1){
			bj2=0;//A
		}
		else {
			l[i]=xl-1;
		}
	}
	qq[1]=a[1];
	for(int i=2;i<=n;i++){
		qq[i]=(a[i]&qq[i-1]);
	}
	hh[n]=a[n];
	for(int i=n-1;i>=1;i--){
		hh[i]=(a[i]&hh[i+1]);
	}
	
	if(bj==1){
		cout<<0;
		return 0;
	}
	if(bj2==1){
		sort(l+1,l+1+n);
		cout<<l[n-m+1];
		return 0;
	}
	if(m==n-1){
		int maxx=hh[2];
		for (int i=2;i<n;i++){
			if(i==3){
				//cout<<qq[i-1]<<" "<<hh[i+1];
			}
			maxx=max(maxx,qq[i-1]&hh[i+1]);
		}
		maxx=max(maxx,qq[n-1]);
		cout<<maxx;
		return 0;
	}
	if(m==n){
    	int q=a[1];
    	for (int i=2;i<=n;i++){
    		q=q&a[i];
		}
		cout<<q;
		return 0;
	}
	if(m==n-1){
		
	}
	for (int i=1;i<=n;i++){
		for (int j=2;j<=min(i,m);j++){
			for (int k=j-1;k<i;k++){
				dp[i][j]=max(dp[i][j],(dp[k][j-1]&a[i]));
			}
		}
	}
	int maxx=0;
	for (int i=1;i<=n;i++){
		maxx=max(maxx,dp[i][m]);
	}
	cout<<maxx;
	return 0;
} 
