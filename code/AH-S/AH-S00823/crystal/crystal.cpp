#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n,m,sum;
int a[5005]; 
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	bool f1=1,f2=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=2;i<n;i++){
		if(a[i]-a[i-1]!=a[i+1]-a[i])f1=0;
		if(a[i]-a[i-1]!=1||a[i+1]-a[i]!=1)f2=0;
	}
	if(f1&&f2){
		int ans=0;
		while((ans+1)*ans/2<=m)ans++;
		cout<<ans;
		return 0;
	}else if(f1&&!f2){
		int ans=0;
		while((a[2]-a[1])*(ans+1)*ans/2<=m)ans++;
		cout<<ans;
		return 0;
	}
	int temp[5005]={0},res=-1;
	for(int i=1;i<=n;i++){
		memset(temp,0,sizeof temp);
		for(int j=1;j<=n;j++){
			temp[j]=a[i]-a[j];
		}
		sort(temp+1,temp+1+n);
		int sum=0,ans=0;
		for(int j=1;j<=n;j++){
			if(sum>m)break;
			else {
				if(temp[j]>=0&&sum+temp[j]<=m){
					ans++;
					sum+=temp[j];
				}
			}
		}
		res=max(res,ans);
	}
	cout<<res;
	return 0;
}
