#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[1000008],b[1000008],w,c[1000008];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		w=0;
		for(int j=i;j<=n;j++){
			int p=0;
			for(int k=1;k<=w;k++){
				if(b[k]==a[j]){
					p=1;
					w=k;
					break;
				}
			}
			if(p==1) b[w]=a[j];
			else w++,b[w]=a[j];
		}
		for(int j=1;j<=w;j++) c[b[j]]++;
	}
	for(int i=1;i<=m;i++) cout<<c[i]<<" ";
	return 0;
}
