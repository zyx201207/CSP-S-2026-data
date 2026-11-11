#include<bits/stdc++.h>
using namespace std;
long long const N=1e8+10;
long long const INF=0X3f3f3f;
int m,n;
int a[N];
int js[N][N];
long long cnt[N];
long long k=-INF;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		js[0][i]=a[i];
	}
	sort(a,a+n+1);
	for(long long i=0;i<=m;i++){
		for(long long j=1;j<=n;j++){
			js[i][j]=js[0][j]+i;
		}
	}
		for(long long i=0;i<=m;i++){
			for(long long j=1;j<=n;j++){
				cnt[js[i][j]]++;
			}
		}
	for(long long i=0;i<m+a[n];i++){
		k=max(k,cnt[i]);
	}
	cout<<k;
	return 0;
}
