#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100000],f[10000][10000]={-1},ans,cnt;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld",&n);
	scanf("%lld",&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=n;j++){
			f[j][i]=a[j]-a[i];
		}
	}
	for(long long j=1;j<=n;j++){
		cnt=m;
		ans=0;
		for(long long i=1;i<=n;i++){
			if(cnt-f[j][i]>=0&&f[j][i]>=0)
			{
				ans++;
				cnt-=f[i][j];
			}
		}
	}
	cout<<ans;
	return 0;
}
