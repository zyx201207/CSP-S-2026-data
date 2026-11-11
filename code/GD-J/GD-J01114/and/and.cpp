#include "bits/stdc++.h"
using namespace std;
int n,m;
int a[200005],b[200005];
int main(void){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int ans=0;
	for(int i=30;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=n;j++)
			if((a[j]>>i)&1) b[++cnt]=a[j];
		if(cnt>=m){
			n=cnt;
			ans+=(1<<i);
			for(int j=1;j<=cnt;j++) a[j]=b[j];
		}
	}
	cout<<ans<<"\n";
	fclose(stdin);
	fclose(stdout);
}
