#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005][31],c[31],f[200005],t[200005],cnt,ans=(1<<30)-1,r;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		t[i]=x;
		for(int j=0;j<31;j++){
			a[i][j]=x&1;
			c[j]+=a[i][j];
			x>>=1;
		}
	}
	r=n;
	for(int i=30;i>=0;i--){
		if(c[i]<m)continue;
		if(r==m)break;
		for(int j=1;j<=n;j++)
			if(!f[j]&&!a[j][i]){
				f[j]=1;
				r--;
				if(r==m)break;
			}
	}
	for(int i=1;i<=n;i++)
		if(!f[i]){
			ans&=t[i];
			cnt++;
			if(cnt==m)break;
		}
	cout<<ans;
	return 0;
}
