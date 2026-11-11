#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,a[10]={0},b[10][10]={0},maxn=INT_MIN;
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
		cin>>a[i];
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=n;j++){
			if(i==j){
				b[i][j]=INT_MAX;
			}long long x=max(a[i],a[j]);
			long long y=min(a[i],a[j]);
			b[i][j]=x-y;
		}
	}for(long long i=1;i<=n;i++){
		long long k[10]={0};
		for(long long j=1;j<=n;j++){
			k[j]=b[i][j];
		}sort(k+1,k+n+1);
		long long cnt=0,ans=0;
		for(long long j=1;j<n;j++){
			if((m-k[j]+cnt)<0)
				break;
			m-=(k[j]-cnt);
			cnt+=(k[j]-cnt);
			ans++;
		}maxn=max(maxn,ans);
	}cout<<maxn;
	return 0;
}
