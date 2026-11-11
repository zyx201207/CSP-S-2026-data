#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500050];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool aflag=true;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i)aflag=false;
	}
	sort(a+1,a+1+n);
	if(m==0){
		long long ans=0;
		long long b[10000000]={0};
		for(long long i=1;i<=n;i++){
			b[a[i]]++;
		}
		int max=b[1];
		for(long long i=2;i<=10000000;i++){
			if(b[i]>max)max=b[i];
		}
		ans=max;
		cout<<ans;
		return 0;
	}
	if(aflag){
		long long k=1,ans=0;
		while(m){
			if(ans>=n-1)break;
			m-=k;
			if(m>=0)ans++;
			k++;
		}
		
		cout<<ans+1;
		return 0;
	}
	long long pre[500050]={0};
	for(long long i=2;i<=n;i++){
		pre[i]=a[i]-a[i-1];
	}
	long long max=0;
	for(long long i=1;i<=n;i++){
		long long w=m,ans=1;
		for(long long j=i;j<=n;j++){
			w-=pre[j]*j;
			if(w>0)ans++;
			if(w==0){
				ans++;
				break;
			}
			if(w<0){
				break;
			}
		}
		if(ans>max)max=ans;
	}
	cout<<max;
	return 0;
} 
