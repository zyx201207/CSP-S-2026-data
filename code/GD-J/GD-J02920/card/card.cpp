#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[10000005],m,b[10000005],c[10000005],d[10000005],ans[10000005];
main(){
	freopen("card.in","r",stdin);
	freopen("card.out","r",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int t=0;
		memset(b,0,sizeof(0));
		for(int j=i;j<=n;j++){
			if(b[a[j]]==1){
				int x=c[a[j]];
				for(int k=x;k<j;k++){
					b[d[k]]=0;
					c[d[k]]=0;
					d[k]=0;
				}
			}
			d[++t]=a[j];
			b[a[j]]=1;
			c[a[j]]=j;
		}
		for(int j=1;j<=t;j++){
			if(d[j]!=0)ans[d[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" "; 
	}
} 
