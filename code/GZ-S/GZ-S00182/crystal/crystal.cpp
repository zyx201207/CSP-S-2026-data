//GZ-S00182 遵义市第五十三中学 王前进
#include<bits/stdc++.h>
using namespace std;
int n;
const int M=5*1e6;
long long m,a[M],d[M],sum[M],cnt[M];
void aians(){
	for(int i=1;i<=n;i++){
		long long ans=0;
		if(d[i]==d[i-1]) d[i-1]=0;
		if(m<=d[i]&&m>=d[i-1]){
			ans=cnt[i]+i-1;
			if(ans>=n){
				cout<<n;return;
			}
			else {
				cout<<ans<<" "; return;
			}
		}
	}
	cout<<n;return;
}
int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	scanf("%ld %lld",&n,&m);
	for(int i=1;i<=n;i++){
		//long long t;cin>>t;
		//a.push_back(t);
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	long long ig=a[1];
	cnt[1]=1;
	for(int i=2;i<n;i++){
		cnt[i]=1;
		if(a[i]==ig){
			cnt[i-1]++;
		}
		else ig=a[i];
	}
	if(cnt[1]==n){ 
		cout<<n;return 0;
	}
	for(int i=1;i<=n;i++){
		d[i]=(i-1)*a[i]-sum[i-1];
		//cout<<d[i]<<" ";
	}
	aians();
	
	return 0;
}
 
