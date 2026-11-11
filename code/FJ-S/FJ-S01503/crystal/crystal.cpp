#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,a[500010],f[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		f[i]=f[i-1]+a[i];
		if(a[i]*(i-1)-f[i-1]<=m){
			ans=i;
		}
		else{
			break;
		}
	}
	cout<<ans;
	return 0;
}
