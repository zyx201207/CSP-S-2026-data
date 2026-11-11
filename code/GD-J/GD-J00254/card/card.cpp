#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+7;
int n,m,k,a[N],s[N],c[N],ans[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) c[i]=-1;
	for(int i=n;i>=1;i--){
		s[i]=c[a[i]];
		c[a[i]]=i;
	}
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++){
			while(s[j]!=-1) j=s[j];
			ans[a[j]]++;
		}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
