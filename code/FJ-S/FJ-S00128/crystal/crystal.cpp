#include<bits/stdc++.h>
using namespace std;
long long m,n;
long long dir[50000005];
long long cnt;
long long a[50000005];
long long maxn=-1;
int main(){
	freopen ("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(m==0){
		cout<<1;
		return 0;
	}
	if(n==1){
		cout<<1;
		return 0;
	}
	
	for(long long i=1;i<=n;i++){
		
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		dir[i]=a[i]-a[1];
	}
	
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=i;j++){
			if(dir[i]-dir[j]<=m){
				maxn=max(maxn,i+1-j);
			}
			
			
		}
	}
	
	cout<<maxn;
	return 0;
}
