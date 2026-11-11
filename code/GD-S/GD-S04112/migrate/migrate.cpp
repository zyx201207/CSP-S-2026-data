#include<bits/stdc++.h>
using namespace std;
long long f,k,a[2000001];
bool vis[2000001];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>f>>k;
	for(long long j=1;j<=k;j++){
		long long n,m;
		memset(a,0,sizeof(a));
		memset(vis,0,sizeof(vis));
		cin>>n>>m;
		long long sum=0;
		for(long long i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]-a[i-1]>m)vis[i]=1;
		}
		for(long long i=1;i<n;i++){
			if(vis[i]==1)continue;
			for(long long c=i+1;c<=n;c++){
				if(vis[c]==1)break;
				if(a[c]-a[i]==2*m-1)sum++;
			}
		}
		cout<<sum<<endl;
	} 
}
