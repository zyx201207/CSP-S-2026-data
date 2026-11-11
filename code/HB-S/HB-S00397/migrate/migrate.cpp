#include<bits/stdc++.h>
using namespace std;
long long n,m,a[2000005],b[2000005],e[2000005],f[2000005],cnt,c,t,d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int k=1;k<=t;k++){
		cin>>n>>d;
		cnt=0;
		memset(b,0,sizeof(b));
		memset(e,0,sizeof(e));
		for(int i=1;i<=n;i++)cin>>a[i];
		a[0]=-1e16-5;
		a[n+1]=1e16+5;
		for(int i=1,j=2;i<=n;i++){
			for(j=max(i+1,j);j<=n;j++){
				if(a[i]+d>=a[j]&&a[i]+d<a[j+1]){
					b[i]=j,e[j]++;
					break;
				}
			}
		}
		for(int i=1,j=2;i<=n;i++){
			for(j=max(i+1,j);j<=n;j++){
				if(a[i]+d>=a[j]&&a[i-1]+d<a[j]){
					f[j]++;
					break;
				}
			}
		}
		for(int i=2;i<=n;i++){
			cnt+=e[i-1]*f[i];
			cout<<e[i]<<" "<<f[i]<<"\n";
		}cout<<cnt<<"\n";
	}
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
