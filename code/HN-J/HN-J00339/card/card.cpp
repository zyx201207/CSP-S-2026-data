#include<bits/stdc++.h>
using namespace std;
const int W=5e5+5;
int n,m,a[W],b[W],ans[W];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	for(int k=1;k<=n;k++){
		int cnt=n;
		for(int i=k;i<=n;i++){
			bool flag=1;
			for(int j=1;j<=cnt;j++){
				if(b[j]==a[i]){
					fill(b+1+j,b+cnt+1,0);
					flag=0;
					cnt=j-1;
				}
			}
			if(flag){
				b[++cnt]=a[i];
			}
		}
		for(int i=1;i<=cnt;i++){
			ans[b[i]]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
