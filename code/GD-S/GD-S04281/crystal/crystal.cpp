#include<bits/stdc++.h>
using namespace std;
long long m,a[500005],p[500005],res;
int n,ans=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	bool flag=0;
	for(int i=2;i<n;i++){
		if(a[i+1]-a[i]!=a[i]-a[i-1]){
			flag=1;
		}
	}
	if(!flag&&n>1){
		int d=a[2]-a[1];
		res=0;
		for(int i=1;;i++){
			res+=i*d;
			if(res>m){
				cout<<i;
				return 0;
			}
		}
	}
	for(int i=1;i<=n;i++){
		res=0;
		for(int j=i+1,t=1;j<=n;j++,t++){
			res+=t*(a[j]-a[j-1]);
			if(res>m){
				ans=max(ans,t);
				break;
			}
			else if(j==n){
				ans=max(ans,t+1);
			}
		}
	}
	cout<<ans;
	return 0;
}
