#include<bits/stdc++.h>
using namespace std;
const int N=5e5+50;
long long n,m,a[N],sum[N],t[N],cnt,l[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	clock_t st=clock();
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
		if(a[i]!=a[i-1]){
			t[++cnt]=a[i];
			l[cnt]=i;
		}
	}long long ans=0,lst=1;
	l[cnt+1]=n+1;
	for(int i=1;i<=cnt;i++){
		long long k=t[i],o=l[i+1]-1;
		for(;lst<=o;lst++){
			long long u=o-lst+1;
			if(k*u-(sum[o]-sum[lst-1])<=m){
				ans=max(ans,u);
				break;
			}
		}
	}cout<<ans<<endl;
//	clock_t et=clock();
//	double tt=double(et-st)/CLOCKS_PER_SEC;
//	cout<<tt<<" s";
	return 0;
}
/*
5 8
-3 -1 2 2 7
7 2
-9 -1 1 1 1 1 6
*/
