#include<bits/stdc++.h>
using namespace std;
int n,m,ans,zd;
int a[500010];
int b[500010]; 
long long sum[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	b[1]=0;
	for(int i=2;i<=n;i++){
		b[i]=(i-1)*a[i]-sum[i-1];
		if(b[i]<=m){
			ans=i;
		}else break;
	}
	cout<<ans;
	return 0;
} 
