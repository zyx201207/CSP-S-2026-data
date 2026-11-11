#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,a[N],s[N],f[N][2],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	f[1][0]=0,f[1][1]=1;
	for(int i=2;i<=n;i++){
		int x=f[i-1][0]+f[i-1][1]*(a[i]-a[i-1]);
		if(x<=m) f[i][0]=x,f[i][1]=f[i-1][1]+1;
		else {
			int y=0,cnt=1;
			for(int j=i-1;j>0;j--) {
				int z=a[i]-a[j];
				if(y+z<=m) cnt++,y+=z;
				else break;
			}
			f[i][0]=y;
			f[i][1]=cnt;
		}
		ans=max(ans,f[i][1]);
	}
	cout<<ans;
//	fclose(stdin);
//	fclose(stdout);
}
