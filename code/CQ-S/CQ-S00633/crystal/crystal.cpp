#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],sum[500005],x[50005],ne=1,num=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) x[i]=x[i-1]+a[n]-a[i];
	if(x[n]<=m){
		cout<<n;
		return 0;
	}for(int i=1;i<=n;i++){
		long long m1=m;
		sum[ne]++;
		if(a[i]==a[i+1]) continue;
		for(int j=i-sum[ne];j>=1;j--){
			if(a[i]-a[j]<=m1){
				m1-=a[i]-a[j];
				sum[ne]++;
			}else break;
		}ne++;
	}sort(sum+1,sum+ne+1);
	cout<<sum[ne]; 
	return 0;
} 
