#include<bits/stdc++.h>
#define int long long
using namespace std;
const int hxy=5e5+7;
int a[hxy],b[hxy],n,m,j,k,l,c[hxy],d[hxy],x,y,ans,sum;
main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		k=0;
		memset(c,0,sizeof(c));
		memset(b,0,sizeof(b));
		for(int j=i;j<=n;j++){
			if(b[a[j]]!=0){
				for(int u=b[a[j]]+1;u<=k;u++) b[c[u]]=0;
				k=b[a[j]];
			}
			else{
				c[++k]=a[j];
				b[a[j]]=k;
			}
		}
		for(int j=1;j<=k;j++){
			d[c[j]]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<d[i]<<" ";
}
