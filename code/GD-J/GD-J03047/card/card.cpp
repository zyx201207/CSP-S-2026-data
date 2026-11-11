#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],f[300005],b[500005]; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		bool ll[300005];
		memset(ll,true,sizeof(ll));
		for(int i=1;i<=n;i++){
		    b[i]=a[i];
	    }
		for(int j=i+1;j<=n;j++){
			if(b[i]==b[j]){
				for(int t=j;t>i;t--) b[t]=-1;
			}
		}
		for(int j=i;j<=n;j++){
			if(b[j]!=-1 && ll[b[j]]){
				ll[b[j]]=false;
				f[b[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++) cout<<f[i]<<" ";
	return 0;
}
