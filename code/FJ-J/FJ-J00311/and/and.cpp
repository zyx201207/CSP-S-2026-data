#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],sum[1],maxn;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	memset(sum,0x3f,sizeof sum);
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==n){
		int cnt[1];
		memset(cnt,0x3f,sizeof cnt);
		for(int i=1;i<=n;i++) cnt[0]&=a[i];
		cout<<cnt[0];
		return 0;
	}
	if(m==1){
		for(int i=1;i<=n;i++) maxn=max(maxn,a[i]);
		cout<<maxn;
		return 0;
	}
	if(m==n-1){
		int cnt[1];
		memset(cnt,0x3f,sizeof cnt);
		for(int i=1;i<=2;i++)
			for(int j=i;j<=i+m-1;j++)
				cnt[0]&=a[i];
		cout<<cnt[0];
		return 0;
	}
	for(int i=1;i+m-1<=n;i++){
		sum[0]=a[i];
		for(int j=i;j<=i+m-1;j++) sum[0]&=a[j];
//		cout<<sum[0]<<endl;
		maxn=max(maxn,sum[0]);
	}
	cout<<maxn;
	return 0;
}
