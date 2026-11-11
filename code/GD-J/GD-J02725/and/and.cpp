#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
bool b;
int a[200005],f[2005][2005],t[10];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i-1)b=1;
		t[min(a[i],5*1ll)]++;
	}
	if(t[5]==0){
		m-=t[3];
		if(m<=0){
			cout<<3;
			return 0;
		}
		int xx=m-t[2],yy=m-t[1];
		if(xx<=0){
			cout<<2;
			return 0;
		}else if(yy<=0){
			cout<<1;
			return 0;
		}
		cout<<0;
		return 0;
	}
	if(n==1){
		cout<<a[1];
		return 0;
	}
	int nn=1,nmb=0;
	while(nn<=n){
		nmb++;
		nn*=2;
	}
	if(nn/2!=n)b=1;
	if(b){
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++){
			f[i][1]=a[i];	
		}
		for(int j=2;j<=m;j++){
			for(int i=j;i<=n;i++){
				f[i][j]=max(f[i][j],f[i-1][j-1]&a[i]);
			}
		}
		int ans=0;
		for(int i=m;i<=n;i++){
			ans=max(ans,f[i][m]);
		}
		cout<<ans;
	}else{
		if(m>n/2)cout<<0;
		else cout<<n-m;
	}
	return 0;
}
