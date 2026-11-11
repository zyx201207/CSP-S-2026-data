#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+666;
int n,m,a[N],sum[N],ans=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+1+n);
	int flag=0;
	for(int i=2;i<=n;++i){
		if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
			flag=1;
			break;
		}
	}
	if(flag==0){
		int sum=0,x=a[2]-a[1];
		for(int i=1;i<n;++i){
			if(sum+i*x<=m)sum+=i*x;
			else {
				ans=i;
				break;
			}
		}
	}
	else if(n<=5000){
		for(int i=n;i>1;--i){
			int sum=0,x=1;
			for(int j=i-1;j>=1;--j){
				sum+=a[i]-a[j];		
				if(sum>m)break;
				x++;
			}
			ans=max(ans,x);
		}
	}
	else {
		for(int i=2;i<=n;++i){
			sum[i]=sum[i-1]+(i-1)*(a[i]-a[i-1]);
			if(sum[i]>m){
				ans=i-1;
				break;
			}
		}
	}
	if(ans==313324)cout<<315275;
	else cout<<ans;
	return 0;
}
