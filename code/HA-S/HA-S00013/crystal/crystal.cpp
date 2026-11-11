#include<bits/stdc++.h>
using namespace std;

long long n,m;
long long a[500010];
long long d[500010];
long long ans;
long long p;//不要前 p 位 
long long sum[500010];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	sort(a+1,a+n+1);
	d[1]=0;
	for(long long i=2;i<=n;i++){
		d[i]=d[i-1]+(a[i]-a[i-1])*(i-1);
		//之前的代价 + 之前所有数变成当前数的代价
		if(d[i]<=m){
			ans=max(ans,i-p);
		}else{
			int temp=d[p];
			while(d[i]-d[p]+temp>m){
				p++;
			}
			d[i]=d[i]-d[p]+temp;
			ans=max(ans,i-p);
		}
	}
	cout<<ans;
	return 0;
}
