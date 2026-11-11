#include<bits/stdc++.h>
using namespace std;
int n,ans=-1;
long long m,a[500100],d[500100];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		d[i]=d[i-1]+a[i+1]-a[i];
	}
//	for(int i=1;i<=n-1;i++) cout<<d[i]<<' ';
//	cout<<'\n';
	for(int i=1;i<n;i++){
		for(int j=i;j<n;j++){
			if(d[j]-d[i-1]>m){
//				cout<<i<<' '<<j<<'\n';
				ans=max(ans,j-i+1);
				break;
			}
		}
	}
	printf("%d",ans);
	return 0;
}
