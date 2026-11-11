#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[1000001],sum=1,mx=-1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	long long cnt=m;
	sort(a+1,a+n+1);
	for(long long i=n;i>=1;i--){
		for(long long j=i-1;j>=1;j--){
			if(a[i]==a[j]){
				sum++;
			}else{
				if(cnt>=(a[i]-a[j])){
					sum++;
					cnt-=(a[i]-a[j]);
				}
			}
			if(cnt<=0) continue;
		}
		cnt=m;
		mx=max(mx,sum);
		sum=1;
	}
	cout<<mx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
