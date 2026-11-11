#include<bits/stdc++.h>
using namespace std;
long long cnt[500005],ans[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[n+5];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m>100000000){
		long long maxn=1;
		long long gong=a[2]-a[1];
		long long chang=a[1]-gong;
		for(long long i=1;i<=n;i++){
			if((a[1]+a[n])/2*i<=m){
				maxn=max(maxn,i);
			}
		}
		cout<<maxn;
	}
	else{
		for(int i=a[1];i<=a[n];i++){
			for(int j=1;j<=n;j++){
				cnt[j]=max(i-a[j],-1ll);
			}
			long long s=0;
			for(int j=1;j<=n;j++){
				if((cnt[j]!=-1)&&(s+cnt[j])<=m){
					ans[i]++;
					s+=cnt[j];
				}
			}
		}
		long long maxnn=-1;
		for(int i=a[1];i<=a[n];i++){
			maxnn=max(maxnn,ans[i]);
		}
		cout<<maxnn;
	}
	return 0;
}
