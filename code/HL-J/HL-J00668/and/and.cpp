#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[200005],dp[200005];
	cin>>n>>m;
	int maxn=0;
	int record=0; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int andsum=a[1];
	for(int i=1;i<=n;i++){
		andsum=(andsum&a[i]);
	}
	if(m==n){
		cout<<andsum;
		return 0;
	}
	if(m==2){
		int ma=0;
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				if((a[i]&a[j])>=ma){
					ma=(a[i]&a[j]);
				}
			}
		}
		cout<<ma;
		return 0;
	}
	sort(a+1,a+n+1); 
	dp[1]=a[n];
	cout<<dp[1]<<' '; 
	a[n]=0;
	for(int i=2;i<=m;i++){
		maxn=0;
		for(int j=1;j<=n;j++){
			//cout<<dp[i-1]<<' '<<a[j]<<' '<<(dp[i-1]&a[j])<<endl;
			//cout<<(dp[i-1]&a[j]);
			if((dp[i-1]&a[j])>=maxn){
				maxn=(dp[i-1]&a[j]);
				record=j;
			}
		}
		
		dp[i]=maxn;
		a[record]=0;
	}
	cout<<dp[m];
	
}
