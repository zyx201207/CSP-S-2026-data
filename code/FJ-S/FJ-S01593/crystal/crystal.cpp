#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m;
int a[N];
int c[N];
int sum,k,ans=-1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c[i-1]=a[i]-a[i-1];
	}
	for(int i=1;i<n;i++){
		sum=0;
		k=0;
		while(sum<=m&&(i+k-1)<n){
			k++;
			for(int j=1;j<=k;j++){
				sum+=c[i+k-1];
			}
			if(sum>m){
				k--;
				ans=max(ans,k+1);
				break;
			}
			ans=max(ans,k+1);
		}
	}
	cout<<ans;
	return 0;
}

