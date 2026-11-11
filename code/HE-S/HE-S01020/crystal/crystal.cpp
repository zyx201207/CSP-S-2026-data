#include<bits/stdc++.h>
using namespace std;
    
const long long n_max=5e5,m_max=1e18;
int n;
long long m;
long long a[n_max+5];
long long dp[n_max+5];//差分表 
    
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		dp[i]=a[i]-a[i-1];
	}
	
	int maxn=0;
	stable_sort(a,a+n); 
	for(int i=0;i<n;i++){//尝试把每一个数作为基准值 
		int tmp_maxn=0,tmp_m=m;
		int p=i-1;
		while(p>=0){
			//把a[p]变成a[i]
			tmp_m-=(a[i]-a[p]);
			if(tmp_m<0) break;
			tmp_maxn++;p--;
		}
		maxn=max(maxn,tmp_maxn);
	}
	cout<<maxn;
	
	return 0;
}   
