#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200005],b[200005],c[200005];
int n,m;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int k=1;
		for(int j=i;j<=n;j++){
			for(int l=1;l<=k;l++){
				if(b[l]==a[j]){
					k=l;
					break;
				}
			}
			b[k]=a[j];
			k++;
		}
		for(int j=1;j<k;j++){
			c[b[j]]++;
			b[j]=0;
		}
	}
	for(int i=1;i<=m;i++)cout<<c[i]<<" ";
	return 0;
}


