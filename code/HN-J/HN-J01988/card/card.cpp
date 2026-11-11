#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+9;
int n,m,a[N],sum1,ans[N],sum2,d[N],k;
map<int,int> b;
map<int,int> c;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		if(b[a[i]]==0){
			b[a[i]]=1;
			sum1++;
		}
	}
	for(int i=1;i<n;i++){
		if(a[i]<=a[i+1]) sum2++;
	}
	if(sum1==n){
		for(int i=1;i<=n;i++){
			ans[a[i]]=i;
		}
		for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
		return 0;
	}
	if(sum2==n-1){
		for(int i=1;i<=n;i++){
			b[a[i]]=1;
		}
		for(int i=1;i<=m;i++){
			if(b[i]==1){
				int x=upper_bound(a+1,a+n+1,i)-a-1;
				cout<<x<<" ";
			}
		}
	} 
	else{
		for(int i=1;i<=n;i++){
			memset(d,0,sizeof(d));
			k=0;
			for(int j=i;j<=n;j++){
				for(int l=1;l<=k;l++){
					if(d[l]==a[j]){
						for(int ii=l;ii<=k;ii++) d[ii]=0;
						break;
					}
				}
				d[++k]=a[j];
			}
			for(int j=1;j<=k;j++) ans[d[j]]++;
			for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
			cout<<'\n';
		}
		for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	}
	return 0;
}
