#include<bits/stdc++.h>

using namespace std;

const int N=5e5+10;

int n,m;
int a[N];
int deep[N],val[N];

int main( void ){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin.tie(0)->sync_with_stdio(false);
	cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	if(a[1]<0){
		for(int i=2;i<=n;i++){
			a[i]+=-a[1];
		}
		a[1]=0;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++){
		val[i]=a[i+1]-a[i];
		deep[i]=deep[i-1]+i*val[i];
	}
	
	deep[n]=deep[n-1];
	int ans=0;
//	for(int i=1;i<=n;i++){
//		tot++;
//		if(deep[i]>m){
//			cout<<tot;
//			return 0;
//		}
//	}
	for(int i=1;i<=n;i++){
		int tot=1;
		for(int j=i+1;j<=n;j++){
			int crl=deep[j-1]-deep[i-1]-(i-1)*(a[j]-a[i]);
			if(crl<=m){
				tot++;
			}
		}
		ans=max(ans,tot);
	}
	cout<<ans<<endl;
	return 0;
}
