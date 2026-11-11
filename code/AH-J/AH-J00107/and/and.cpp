#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	LL n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==2){
		long long maxn=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j) maxn=max(maxn,(a[i]&a[j]));
			}
		}
		cout<<maxn;
		return 0;
	}
	if(m==n){
		long long sum=0;
		for(int i=1;i<=n-1;i++){
			sum+=a[i]&a[i+1];
		}	
		cout<<sum;
		return 0;
	}	
	if(m==n-1){
		long long sum1=0,sum2=0;
		for(int i=1;i<=n-2;i++){
			sum1+=a[i]&a[i+1];
		}	
		for(int i=2;i<=n-1;i++){
			sum2+=a[i]&a[i+1];
		}	
		cout<<max(sum1,sum2);
		return 0;
	}	
	if(m==1){
		for(int i=1;i<=n;i++){
			maxn=max(maxn,a[i]&a[i]);
		}	
		cout<<maxn;
		return 0;
	}	
	return 0;
}
