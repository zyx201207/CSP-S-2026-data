#include<bits/stdc++.h>
#define int long long
#define uint unsigned long long
using namespace std;
const int mo1=1e9+7,mo2=1e9+9;
int n,m,a[500010],b[500010],z[300010],f[300010],si;
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int t=1;t<=n;t++){
		memset(b,0,sizeof b),memset(f,0,sizeof f),si=0;
		for(int i=t;i<=n;i++)
			if(f[a[i]]>0){
				for(int j=f[a[i]]+1;j<=si;j++) f[b[j]]=0,b[j]=0;
				si=f[a[i]];
			}
			else b[++si]=a[i],f[a[i]]=si;
		for(int i=1;i<=si;i++) z[b[i]]++;
	}
	for(int i=1;i<=m;i++) cout<<z[i]<<' ';
}
signed main(){
	ios::sync_with_stdio(0),
	cin.tie(0),cout.tie(0);
	freopen("card.in" , "r" , stdin);
	freopen("card.out" , "w" , stdout);
	int T=1;
//	cin>>T;
	while(T--) solve();
	return 0;
}
