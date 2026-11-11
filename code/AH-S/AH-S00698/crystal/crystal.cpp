#include<bits/stdc++.h>
using namespace std;
long long n;
long long m,cnt,t;
long long a[500005],sum[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(long long i=1;i<=n;i++){
		while(t<i){
			if(m<(i-t-1)*a[i]-(sum[i]-sum[t]))t++;
			else{
				cnt=max(i-t-1,cnt);
				break;
			}
		}
	}
	cout<<cnt;
	return 0;
}
