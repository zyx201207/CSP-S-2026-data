#include <bits/stdc++.h>
using namespace std;
long long a[20000001];//c_c_f
long long i;	long long n,m;
long long findm(long long x){
	int p=m;
	int t=1;//f
	for(long long j=x-1;j>=1;j--){
		if(a[x]-a[j]<=p){
			t++;
			p=p-(a[x]-a[j]);//k
		}
		else{
			return t;
		}
	}
	return t;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;//c
	for(i=2;i<=n;i++){
		cin>>a[i];
	}
	int ans=0;
	if(n<=5000){
		sort(a+1,a+n+1);
		for(long long i=2;i<=n;i++){
			int tot=findm(i);
			ans=max(ans,tot);
		}
		cout<<ans;
		return 0;
	}
	else{
		long long d=a[2]-a[1];
		for(long long i=1;i<=n;i++){
			if(d*(i+1)*i/2<=m){
				ans=i+1;
			}
			else{
				break;
			}
		}
		cout<<ans;
		return 0;//u
	}
}
