#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,m,a[N],sum[N],p=1,q=1,ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	while(p<=n){
		int aim=a[p]*(p-q+1);
		if(sum[p]-sum[q-1]+m>=aim){
			ans=max(ans,p-q+1);
			p++;
		}else{
			q++;
		}
	}
	cout<<ans<<"\n";
	return 0;
}




















